#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n, m;
  long a=0;

  cin>>n;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin>>m;
      if (i == j) {
        a += m;
      }

      if (i+j==n-1) {
        a -= m;
      }
    }
  }

  cout<<abs(a)<<endl;

  return 0;
}
