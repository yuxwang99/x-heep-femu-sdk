import numpy
import os


def get_c_array(data, name="data", type="int", dim=1):
    """
    Get C array from numpy array.

    :param data: numpy array
    :param name: name of the array
    :return: C array
    """
    data_str = ",\n".join([str(x) for x in data])
    return type + " " + name + "[" + str(dim) + "] = {" + data_str + "};"


def write_data_to_header(
    data_all, header_file, matix_names=["data"], types=["float"], dims=[1]
):
    """
    Write data to header file.

    :param data: data to write
    :param header_file: header file to write data to
    """
    # Open header file
    if len(matix_names) != len(data_all):
        print("Error: len(matix_names) != len(data_all)")
        return

    c_prefix = "#ifndef DATA_H\n#define DATA_H"
    c_postfix = "#endif"

    # Find the line that contains the data
    file_string = c_prefix + "\n"
    for i in range(len(matix_names)):
        data = data_all[i]
        name = matix_names[i]
        arr_type = types[i]
        dim = dims[i]
        lines = []
        c_array = get_c_array(
            data,
            name,
            arr_type,
            dim=dims[i],
        )
        file_string += c_array + "\n"

    file_string += c_postfix

    # Write to header file
    with open(header_file, "w") as f:
        f.writelines(file_string)


# read data matrix from txt file
ecg_data = numpy.loadtxt("./seizure/extern_input_256/ECG_36_0.txt")
spo2_data = numpy.loadtxt("./seizure/extern_input_256/Spo2_36_0.txt")

# header file name
header_file = "./seizure/include/data.h"

write_data_to_header(
    [ecg_data, spo2_data],
    header_file,
    matix_names=["ECG_MATRIX", "SPO2_MATRIX"],
    types=["float", "float"],
    dims=[30720, 30720],
)
