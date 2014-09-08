#include <iostream>

using namespace std;

int main() {
  int n, t, sum, d, n2;

  cin>>t;
  for (int l=0; l<t; l++) {
    sum = 0;
    cin>>n;
    n2 = n;
    while (n>0) {
      d = n % 10;
      n = n / 10;

      if (d != 0 and n2 % d == 0) {
        sum++;
      }
    }

    cout<<sum<<endl;
  }

  return 0;
}
