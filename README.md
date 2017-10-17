# FT-Isort

stl_algo.h: implemented the fault injection to quicksort procedure and compute 3 times of checksums to protect the array from memory errors.

stl_heap.h: implemented the fault injection to heapsort procedure.

The above 2 files together implemented:

1. Fault tolerant instrosort protected by Aggressive protection with and/or without memory protection.

Plus another file, correct_only.h which implemented Algorithm 5 in our paper, all the 3 files together implemented: 

2. Fault tolerant introsort protected by Convervative protection with and/or without memory protection.

To test the fault tolerant introsot:

1. Install gcc-7.1.0 and replace /include/c++/7.1.0/bits/stl_algo.h and stl_heap.h with our modifed ones.

2. Run the program, test_ft_isort.cpp, to test different protection methods.



Expected results as in Table 2 of our paper:

Fault free run of std::sort:                                      101.3 seconds

std::sort with Conservative protection (mem and comp protection): 109.3 seconds

std::sort with Conservative protection (only comp protection):    103.8 seconds

std::sort with Aggressive protection (mem and comp protection):   104.3 seconds

std::sort with Aggressive protection (only comp protection):      101.1 seconds


Thank you very much!
