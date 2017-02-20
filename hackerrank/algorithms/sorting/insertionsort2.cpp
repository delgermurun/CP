#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

void sort(int position, int * ar) {
  int n = ar[position];

  int i = position - 1;
  int tmp_at = ar[i];

  while (i>-1 && tmp_at > n) {
    ar[i+1] = ar[i];
    i--;
    if (i>-1) {
      tmp_at = ar[i];
    }
  }

  ar[i+1] = n;
}

void printArray(int ar_size, int * ar) {
  for (int i=0; i<ar_size; i++) {
    cout<<ar[i]<<" ";
  }
  cout<<endl;
}

void insertionSort(int ar_size, int * ar) {
  for (int i=1; i<ar_size; i++) {
    sort(i, ar);
    printArray(ar_size, ar);
  }
}

int main(void) {
    int _ar_size;
    cin >> _ar_size;
    //scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        cin >> _ar[_ar_i];
        //scanf("%d", &_ar[_ar_i]); 
    }

   insertionSort(_ar_size, _ar);
   
   return 0;
}
