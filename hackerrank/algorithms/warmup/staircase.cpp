#include <iostream>

using namespace std;

int main() {
  int n, j;
  long long a, sum = 0;

  cin>>n;
  for (int i=n-1; i>=0; i--) {
    for (j=0; j<i; j++) {
      cout<<" ";
    }
    for (j=0; j<n-i; j++) {
      cout<<"#";
    }
    cout<<endl;
  }

  return 0;
}
