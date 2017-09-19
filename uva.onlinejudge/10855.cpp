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

char big[500][500], small[500][500];

void rotate(int n)
{
  char r[500][500];

  REP(i, 0, n / 2 + 1)
  {
    REP(j, i, n - i - 1)
    {
      r[j][n - i - 1] = small[i][j];

      r[j][i] = small[n - i - 1][j];
    }

    REP(j, i + 1, n - i - 2)
    {
      r[i][n - j - 1] = small[j][i];

      r[n - i - 1][n - j - 1] = small[j][n - i - 1];
    }
  }

  REP(i, 0, n - 1)
  {
    REP(j, 0, n - 1)
    {
      small[i][j] = r[i][j];
    }
  }
}

int find(int N, int n)
{
  int c = 0;
  bool f;

  REP(i, 0, N - n)
  {
    REP(j, 0, N - n)
    {
      f = true;

      REP(ii, 0, n - 1)
      {
        REP(jj, 0, n - 1)
        {
          if (big[i + ii][j + jj] != small[ii][jj])
          {
            f = false;
            break;
          }
        }

        if (!f)
          break;
      }

      if (f)
      {
        c++;
      }
    }
  }

  return c;
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int N, n;
  while (scanf("%d %d\n", &N, &n), N > 0)
  {
    REP(i, 0, N - 1)
    {
      scanf("%s", big[i]);
    }

    REP(i, 0, n - 1)
    {
      scanf("%s", small[i]);
    }

    printf("%d ", find(N, n));
    rotate(n);

    printf("%d ", find(N, n));
    rotate(n);

    printf("%d ", find(N, n));
    rotate(n);

    printf("%d\n", find(N, n));
  }

  return 0;
}