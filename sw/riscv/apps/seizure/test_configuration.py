import subprocess
import csv
import numpy as np
import pandas as pd

def get_key_info_pair(output_str):
    lines = output_str.split('\n')
    pair = {}
    for line in lines:
        if line.strip() == "" or line.startswith("mask_ind") or line.startswith("using"):
            continue
        key, value = line.split(":")[0].strip(), float(line.split(":")[1].strip())
        pair[key] = value
    pair['Segment'] = 0
    return pair

# Define the executable and configuration
# executable_path = "./IterPlus_seizure"
test_times = 5
subjects = [36, 41, 45, 50, 56, 60, 62, 78, 84]

info_file_name = f"./python_results/PC_M2toM5_Confp50top80.csv"
mask_indices = ["-1 -1 -1 3 4" , "0 -1 -1 3 4", "0 1 -1 3 4", "0 1 2 3 4"]
conf_seiz = np.array([0.5, 0.6, 0.7, 0.8])

# mask_indices = [ "0 1 -1 3 4"]
# conf_seiz = [0.8]

# info_file_name = f"./python_results/PC_m12345_Conf0.csv"
# mask_indices = ["0 -1 -1 -1 -1", "-1 1 -1 -1 -1", "-1 -1 2 -1 -1", "-1 -1 -1 3 -1", "-1 -1 -1 -1 4"]
# conf_seiz = [0]
 # the table is consists of the subjects, type index, and segment pieces

df = pd.DataFrame()
# df.set_index('Subject', inplace=True)
for mask in mask_indices:
    for conf_val in conf_seiz:
        for subject in subjects:
            for type_ind in range(2):
                # iterative arguments
                arguments_iter = ["./Iterative_seizure"] + \
                        [str(subject)] + \
                        [str(type_ind)] + \
                        ['256'] + \
                        [str(conf_val)] + mask.split(' ')
                        
                arguments_plus = ["./IterPlus_seizure"] + \
                        [str(subject)] + \
                        [str(type_ind)] + \
                        ['256'] + \
                        [str(conf_val)] + mask.split(' ')
                        
                arguments_base = ["./Iterative_seizure"] + \
                        [str(subject)] + \
                        [str(type_ind)] + \
                        ['256'] + \
                        ["0"] + "-1 -1 -1 -1 4".split(' ')
                        
                runtime_iter_vec = []
                runtime_plus_vec = []
                runtime_full_vec = []
                reduced_runtime_vec = []
                
                mask_runtime = np.empty((0, 5), float)
                merge_info = {}
                for i in range(test_times):
                    process_iter = subprocess.Popen(arguments_iter, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                    output, errors = process_iter.communicate()
                    output = output.decode('utf-8') 
                    info = get_key_info_pair(output)
                    runtime_iter_vec.append(info["total runtime"])
                    reduced_runtime_vec.append(info["saveup time"])
                    merge_info = {key: info[key] for key in ["confidence", "Nmodels", "Subject", "Type", "Segment", "Pred", "True", "Mask"]}
                    
                    process_plus = subprocess.Popen(arguments_plus, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                    output, errors = process_plus.communicate()
                    output = output.decode('utf-8') 
                    info = get_key_info_pair(output)
                    runtime_plus_vec.append(info["total runtime"])
                    mask_dict = {"m"+str(i)+" runtime": info["m"+str(i)+" runtime"] for i in range(1,6)}
                    mask_runtime_i = np.array(list(mask_dict.values()))
                    mask_runtime = np.append(mask_runtime, [mask_runtime_i], axis=0)

                    process_base = subprocess.Popen(arguments_base, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                    output, errors = process_base.communicate()
                    output = output.decode('utf-8') 
                    info = get_key_info_pair(output)
                    runtime_full_vec.append(info["total runtime"])
                    
                for i in range(5):
                    merge_info["m"+ str(i+1)+ " runtime"] =  np.mean(mask_runtime, axis=0)[i]
                merge_info["iterative runtime"] = sum(runtime_iter_vec)/len(runtime_iter_vec)
                merge_info["iterPlus runtime"] = sum(runtime_plus_vec)/len(runtime_plus_vec)
                merge_info["full runtime"] = sum(runtime_full_vec)/len(runtime_full_vec)
                merge_info["saveup time"] = sum(reduced_runtime_vec)/len(reduced_runtime_vec)
                
                print(merge_info)
                # print(output)
                new_df = pd.DataFrame([merge_info])
                df = df.append(new_df)
df.to_csv(info_file_name, index=False)