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

void partition(vector <int>  ar) {
  vector <int>  sar;
  vector <int>  bar;

  int p = ar.front();
  for (int i=1; i<ar.size(); i++) {
    if (ar.at(i) > p) {
      bar.push_back(ar.at(i));
    } else {
      sar.push_back(ar.at(i));
    }
  }

  for (int i=0; i<sar.size(); i++) {
    cout<<sar.at(i)<<" ";
  }
  cout<<p<<" ";
  for (int i=0; i<bar.size(); i++) {
    cout<<bar.at(i)<<" ";
  }
  cout<<endl;
}

int main(void) {
   vector <int>  _ar;
   int _ar_size;
   cin >> _ar_size;
   for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
     int _ar_tmp;
     cin >> _ar_tmp;
     _ar.push_back(_ar_tmp); 
   }

   partition(_ar);
   return 0;
}
