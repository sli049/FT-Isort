#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include<algorithm>
#include "correct_only.h"

using namespace std;

int main(){
    int n = 134217728*4; //2^29 double precision floating numbers to be sorted
    cout << endl << "n is "<< n << endl;
    double* s =  new double[n];
    clock_t start, end;
    
    start = clock();
    srand((unsigned) time(NULL));
    for (int i = 0; i < n; i++)
       s[i] = (double) rand()/RAND_MAX;//generate random data to be sorted
    end = clock();
    
    cout<<endl<< "initialization is "<< (double)(end-start)/CLOCKS_PER_SEC<<" s."<<endl;

    start = clock();

    //use this code if you want to test the original std::sort without errors
        sort(s, s+n);

    //use this code if you want to test conservative protection with memory protection
        //sort_err_mem_cons(s, s+n);
        //cons_correction(s, n);

    //use this code if you want to test aggressive protection with memory protection
        //sort_err_mem_agg(s, s+n);

    //use this code if you want to test conservative protection without memory protection
        //sort_err_cons(s, s+n);
        //cons_correction(s, n);

    //use this code if you want to test aggressive protection without memory protection
        //sort_err_agg(s, s+n);

    end = clock();
    cout << "total sorting time is " <<(double)(end-start)/CLOCKS_PER_SEC <<" s." <<endl;
   return 0;
    
}
