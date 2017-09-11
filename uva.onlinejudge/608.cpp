#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
// typedef vector<int> vi;
// typedef pair<int,int> pi;

#define REP(i, a, b) for (int i = a; i <= b; i++)
// REP(i,1,n) {
//   search(i);
// }


int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  #endif

  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  char c;
  string w[3][3];
  cin >> n;

  REP(i, 1, n) {
    REP(j, 0, 2) {
      cin >> w[j][0] >> w[j][1] >> w[j][2];
      // cout << w[0][0] << w[0][1] << w[0][2] << "\n";
    }

    for (c = 'A'; c <= 'L'; c++) {
      REP(j, 0, 2) {
        if (w[j][2] == "even" && (w[j][0].find(c) != string::npos || w[j][1].find(c) != string::npos)) {
          continue;
        }
      }
    }

    cout << c << "\n";
  }

  return 0;
}