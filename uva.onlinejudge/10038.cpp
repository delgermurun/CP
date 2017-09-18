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
  ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif

  bool j;
  int n, d, c;
  int a[3000];

  while (cin >> n)
  {
    j = true;
    fill(a, a + n, 0);

    cin >> c;
    REP(i, 1, n - 1)
    {
      cin >> d;
      a[abs(c - d)] = 1;

      c = d;
    }

    if (n != 1)
    {
      REP(i, 1, n - 1)
      {
        if (a[i] == 0)
        {
          j = false;
          break;
        }
      }
    }

    if (j)
    {
      cout << "Jolly\n";
    }
    else
    {
      cout << "Not jolly\n";
    }
  }
  return 0;
}