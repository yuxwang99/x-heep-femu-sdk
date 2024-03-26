
#!/bin/bash

# Define info_file_name
info_file_name="./python_results/PC_m12345_Conf0.csv"
echo "info_file_name"

# Define mask_indices array
mask_indices=("0 -1 -1 -1 -1" "-1 1 -1 -1 -1" "-1 -1 2 -1 -1" "-1 -1 -1 3 -1" "-1 -1 -1 -1 4")
# subjects=(36 41 45 50 56 60 62 78 84)
# Define conf_seiz array
subjects=(36)
conf_seiz=(0)
test_times=1

# Define functions to get key-value pairs from output
get_key_info_pair() {
    local output="$1"
    local key="$2"
    echo "$output" | grep -o "(?<=${key}: )[0-9.]+"
}

# Initialize DataFrame
df=""

# Iterate over mask indices
for mask in "${mask_indices[@]}"; do
    for conf_val in "${conf_seiz[@]}"; do
        for subject in "${subjects[@]}"; do
            for type_ind in {0..1}; do
                # Define arguments for iterative execution
                arguments_iter=(
                    ./Iterative_seizure
                    $subject
                    $type_ind
                    $conf_val
                    ${mask[@]}
                )

                # Define arguments for iterative plus execution
                arguments_plus=(
                    ./IterPlus_seizure $subject
                    $type_ind
                    $conf_val
                    ${mask[@]}
                )

                # Define arguments for base execution
                arguments_base=(
                    ./Iterative_seizure $subject $type_ind 0 -1 -1 -1 -1 4
                )

                # Initialize arrays for runtime tracking
                runtime_iter_vec=()
                runtime_plus_vec=()
                runtime_full_vec=()
                reduced_runtime_vec=()

                # Initialize mask runtime
                mask_runtime=()

                # Run tests for specified number of times
                for ((i=0; i<test_times; i++)); do
                    # Execute base command
                    # echo "${arguments_base[@]}"
                    output=$("${arguments_base[@]}")
                    info=$(get_key_info_pair "$output" "total runtime")
                    runtime_full_vec+=("$info")

                    # # Execute iterative command
                    output=$("${arguments_iter[@]}")

                    echo "${arguments_iter[@]}"
                    echo $output

                    info=$(get_key_info_pair "$output" "total runtime")
                    runtime_iter_vec+=("$info")
                    info=$(get_key_info_pair "$output" "saveup time")
                    reduced_runtime_vec+=("$info")

                    # # Execute iterative plus command
                    output=$("${arguments_plus[@]}")
                    info=$(get_key_info_pair "$output" "total runtime")
                    runtime_plus_vec+=("$info")

                    # Extract mask runtime info
                    for ((j=1; j<=5; j++)); do
                        mask_val=$(get_key_info_pair "$output" "m${j} runtime")
                        mask_runtime+=("$mask_val")
                    done
                done

                # Calculate average mask runtime
                # mask_runtime_sum=$(IFS=+; bc <<<"${mask_runtime[*]}")
                # mask_runtime_avg=$(echo "scale=4; $mask_runtime_sum / $test_times" | bc)

                # # Calculate averages for other runtimes
                # iter_runtime_avg=$(echo "scale=4; (${runtime_iter_vec[*]} / $test_times)" | bc)
                # plus_runtime_avg=$(echo "scale=4; (${runtime_plus_vec[*]} / $test_times)" | bc)
                # full_runtime_avg=$(echo "scale=4; (${runtime_full_vec[*]} / $test_times)" | bc)
                # reduced_runtime_avg=$(echo "scale=4; (${reduced_runtime_vec[*]} / $test_times)" | bc)

                # # Print formatted merge info
                # printf -v formatted_merge_info \
                #     '{"Nmodels": %d, "Subject": %d, "Type": %d, "Pred": %d, "True": %d, "Mask": %d, "confidence": %.4f, "iterative runtime": %.4f, "iterPlus runtime": %.4f, "full runtime": %.4f, "saveup time": %.4f, "m1 runtime": %.4f, "m2 runtime": %.4f, "m3 runtime": %.4f, "m4 runtime": %.4f, "m5 runtime": %.4f}' \
                #     "$Nmodels" "$Subject" "$Type" "$Pred" "$True" "$Mask" "$conf_val" "$iter_runtime_avg" "$plus_runtime_avg" "$full_runtime_avg" "$reduced_runtime_avg" "$mask_runtime_avg" "$mask_runtime_avg" "$mask_runtime_avg" "$mask_runtime_avg" "$mask_runtime_avg"

                # echo "$formatted_merge_info"

                # # Add to DataFrame (if needed)
                # df=$(jq -s '. + [.]' <<<"$df")
            done
        done
    done
done
