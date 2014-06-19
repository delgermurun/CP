#include <iostream>

using namespace std;

int main() {
  int l, r, ans=0, t;

  cin>>l>>r;
  for (int i=l; i<r; i++) {
    for (int j=i; j<=r; j++) {
      t = i^j;
      if (ans < t) {
        ans = t;
      }
    }
  }
  cout<<ans<<endl;
}
