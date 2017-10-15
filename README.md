# FT-Isort
To test the fault tolerant introsot:

1. Install gcc-7.1.0 and replace /include/c++/7.1.0/bits/stl_algo.h and stl_heap.h with our modifed ones.
2. Our modified files will implement the fault injection from source code level and they will compute 3 times of
checksums to protection the array from memory errors.
3. 
