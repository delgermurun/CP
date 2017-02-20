#include <iostream>

using namespace std;

long calculate_min_unit(long u, long h) {
  long d;

  if (u > h) {
    d = u;
    u = h;
    h = d;
  }

  d = h - u;
  u += d / 2;
  u += d % 2;

  return u;
}

int main() {
  long n, u=0;

  cin >> n;
  long h[n];

  for (int i=0; i<n; i++) {
    cin>>h[i];
  }

  for (int i=n-1; i>=0; i--) {
    u = calculate_min_unit(u, h[i]);
  }

  cout<<u<<endl;
  return 0;
}
