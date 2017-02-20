#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int t, l, ans;
  string s;
  cin>>t;

  for (int i=0; i<t; i++) {
    cin>>s;
    l = s.size();

    ans = 0;
    for (int j=0; j<l/2; j++) {
      ans += abs(s[j] - s[l-j-1]);
    }
    cout<<ans<<endl;
  }
  return 0;
}
