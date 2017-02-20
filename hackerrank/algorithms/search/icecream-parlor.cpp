#include <iostream>

using namespace std;

void solve(int n, int m, int a[10000]) {
  bool f = false;

  for (int i=0; i<n-1 && !f; i++) {
    for (int j=i+1; j<n && !f; j++) {
      if (a[i] + a[j] == m) {
        cout<<i+1<<" "<<j+1<<endl;
        f = true;
      }
    }
  }
}

int main() {
  int t, n, m;
  int a[10000];

  cin>>t;
  for (int i=0;i<t;i++) {
    cin>>m>>n;
    for (int j=0;j<n;j++) {
      cin>>a[j];
    }
    solve(n, m, a);
  }

  return 0;
}
