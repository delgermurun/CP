#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int n, a;
  float plus=0, minus=0, zero=0;

  cin>>n;
  for (int i=0; i<n; i++) {
    cin>>a;
    if (a>0) {
      plus += 1;
    } else if (a<0) {
      minus += 1;
    } else {
      zero += 1;
    }

  }

  plus = plus/n;
  minus = minus/n;
  zero = zero/n;

  printf("%4.3f\n", plus);
  printf("%4.3f\n", minus);
  printf("%4.3f\n", zero);

  return 0;
}
