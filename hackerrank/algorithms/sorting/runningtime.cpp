#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

int sort(int position, int * ar) {
  int n = ar[position];
  int c = 0;

  int i = position - 1;
  int tmp_at = ar[i];

  while (i>-1 && tmp_at > n) {
    c++;
    ar[i+1] = ar[i];
    i--;
    if (i>-1) {
      tmp_at = ar[i];
    }
  }

  ar[i+1] = n;
  return c;
}

void insertionSort(int ar_size, int * ar) {
  int c = 0;
  for (int i=1; i<ar_size; i++) {
    c += sort(i, ar);
  }
  cout<<c<<endl;
}

int main(void) {
    int _ar_size;
    cin >> _ar_size;
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        cin >> _ar[_ar_i];
    }

   insertionSort(_ar_size, _ar);
   
   return 0;
}
