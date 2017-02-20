#include <iostream>

using namespace std;

int main() {
  long long p, q, r, l, t;
  long long n;
  int a[20] = {0}, j;
  bool found = false;

  cin>>p>>q;

  for (int i=p;i<=q;i++) {
    j = 0;
    n = (long long)i*i;

    while (n!=0) {
      a[j] = n % 10;
      n /= 10;
      j++;
    }

    r = 0; t = 1;
    for (int k=1; k<=(j/2 + j%2); k++) {
      r += t * a[k-1];
      t *= 10;
    }

    l = 0; t = 1;
    for (int k=(j/2 + j%2 + 1); k<=j; k++) {
      l += t * a[k-1];
      t *= 10;
    }
    
    if (r + l == i) {
      found = true;
      cout<<i<<" ";
    }
  }

  if (!found) {
    cout<<"INVALID RANGE";
  }

  cout<<endl;

  return 0;
}
