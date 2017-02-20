#include <iostream>

using namespace std;

int main() {
  int t;
  long long int k;

  cin>>t;

  for (int i=0; i<t; i++) {
    cin>>k;
    k = (k/2) * (k/2) + ((k%2) * (k/2));
    cout<<k<<endl;
  }
  return 0;
}
