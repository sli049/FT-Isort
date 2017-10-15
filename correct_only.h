#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cons_correction (float* s, int n){
    //clock_t start, end, tk_out, sft_l, bi_isrt, sft_r;
   // start = clock();
    float* tkele = new float[500];
    int* tkloc = new int[500];

	int arraysz = 0;
	int ti = 0;
	int bound = n-1;
	while (ti < bound){
	 if (s[ti] > s[ti+1]){
            if (!(s[ti-1] > s[ti+1])) {
               tkele[arraysz] = s[ti];
		tkloc[arraysz] = ti;
            }
            else {
               tkele[arraysz] = s[ti+1];
		tkloc[arraysz] = ti+1;
            }
		arraysz++;
        }
	
		ti++;
	}
    int sz = arraysz;
    if (sz == 0){
       // end = clock();
     //   cout << endl << "there is no fault, time consumption is " << (double)(end-start)/CLOCKS_PER_SEC<<" s." << endl;
        return 0;
    }

    int i, j, ending;
    for (i=1; i < sz; i++ ){
        ending = tkloc[i];
        for (j = tkloc[i-1]+1; j < ending; j++)
            s[j-i] = s[j];
    }
    j++;
    if (i == 1) j = tkloc[0]+1;
    for (; j < n; j++)
        s[j-i] = s[j];//end shift left
    
    sort(tkele, tkele+sz);
    

    int a, b;
    a = 0; b = n-sz-1;
    float value = tkele[0];
    //vector<int> tkloc1;
    bool cond = true;

    while (cond){
            i = a + (b-a)/2;
            if (value > s[i]) a = i+1;
            else if (value > s[i-1]){ 
                tkloc[0] = i;
                cond = false;
            } else b = i-1;
        }

    for (int loop = 1; loop < sz; loop++){
        value = tkele[loop];
        a = tkloc[loop-1]; b = n-sz-1;cond = true;
        while (cond){
            i = a + (b-a)/2;
            if (value > s[i]) a = i+1;
            else if (value > s[i-1]){ 
                tkloc[loop] = i;
                cond = false;
            } else b = i-1;
        }
    }

    //shift right
    ending = tkloc[sz-1] - 1;
    for (j = n-1-sz; j > ending; j--)
        s[j+sz] = s[j];
    s[j+sz] = tkele[sz-1];
    
    for ( i = sz - 1; i > 0; i--){
        ending = tkloc[i-1] - 1;
        for ( j = j+i; j > ending; j--)
            s[j] = s[j-i];
        s[j+i] = tkele[i-1];
    } 

    //end = clock();
    
   // cout<<endl<< "my correction "<< (double)(end-start)/CLOCKS_PER_SEC<<" s."<<endl;
    
/*	int counter = 0;
    for (int i = 0; i < n - 1; i++){
        if (s[i] > s[i+1]) counter++;
    }
    if (counter == 0) cout << "my correction is correct."<<endl;
    else cout << "my correcrtion is not correct. There are "<< counter << " errors." << endl;
  */  
    return 0;
    
}
