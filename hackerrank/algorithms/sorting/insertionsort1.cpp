#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void printVector(vector <int>  ar) {
  for (int _ar_i=0; _ar_i<ar.size(); _ar_i++) {
    cout<<ar.at(_ar_i)<<" ";
  }

  cout<<endl;
}

void insertionSort(vector <int>  ar) {
  int ar_size = ar.size();
  int n = ar.back();

  int i = ar_size-2;
  int tmp_at = ar.at(i);

  while (i > -1 && tmp_at > n) {
    ar.at(i+1) = ar.at(i);
    printVector(ar);

    i--;
    if (i>-1) {
      tmp_at = ar.at(i);
    }
  }
  ar.at(i+1) = n;

  printVector(ar);
}

int main(void) {
  vector <int> _ar;
  int _ar_size;
  cin >> _ar_size;

  for (int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
    int _ar_tmp;
    cin >> _ar_tmp;
    _ar.push_back(_ar_tmp); 
  }

  insertionSort(_ar);
  return 0;
}
