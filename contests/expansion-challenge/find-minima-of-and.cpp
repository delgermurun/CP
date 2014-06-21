#include <iostream>

using namespace std;

int main() {
  long long int t, n, m, ans;

  cin>>t;
  for (int i=0; i<t; i++) {
    cin>>n;
    cin>>ans;

    for (int j=1; j<n; j++) {
      cin>>m;
      ans &= m;
    }
    cout<<ans<<endl;
  }
  return 0;
}
