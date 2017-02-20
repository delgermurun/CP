#include <iostream>

using namespace std;

int main() {
  int t, n, m, c, ans;

  cin>>t;
  for (int i=0; i<t; i++) {
    cin>>n>>c>>m;
    ans = n/c;
    n = ans;

    while (n >= m) {
      ans += n/m;
      n = n/m + n%m;
    }
    cout<<ans<<endl;
  }
}
