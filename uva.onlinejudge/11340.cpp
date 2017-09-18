#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

typedef long long ll;
// typedef vector<int> vi;
// typedef pair<int, int> pi;

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

  map<char, int> p;
  map<char, int>::iterator it;

  double t;
  int n, k, c, m, l;
  char ch;
  string s;
  cin >> n;

  REP(ii, 1, n)
  {
    t = 0;
    p.clear();

    cin >> k;

    REP(i, 1, k)
    {
      cin >> ch >> c;
      p[ch] = c;
    }

    cin >> m;
    cin.ignore();

    REP(i, 1, m)
    {
      s = "";
      getline(cin, s);

      l = s.size();
      REP(j, 0, l - 1)
      {
        it = p.find(s[j]);
        if (it != p.end())
          t += it->second;
      }
    }

    printf("%.2lf$\n", t / 100);
  }

  // printf("%.9f\n", x);
  // solution comes here
  return 0;
}