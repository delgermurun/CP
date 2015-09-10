#include <iostream>

using namespace std;

int main() {
  int t, n, k, s, a;

  cin>>t;
  for (int i=0;i<t;i++) {
    cin>>n>>k;

    s = 0;
    for (int j=0;j<n;j++) {
      cin>>a;
      if (a<=0) {
        s++;
      }
    }

    if (s>=k) {
      cout<<"NO"<<endl;
    } else {
      cout<<"YES"<<endl;
    }
  }

  return 0;
}
