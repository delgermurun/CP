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

int g[3][3];

int f()
{
  int gg[3][3];
  int t;
  int s = 0;

  REP(i, 0, 2)
  {
    REP(j, 0, 2)
    {
      t = 0;

      if (i > 0)
      {
        t += g[i - 1][j];
      }
      if (i < 2)
      {
        t += g[i + 1][j];
      }
      if (j > 0)
      {
        t += g[i][j - 1];
      }
      if (j < 2)
      {
        t += g[i][j + 1];
      }

      gg[i][j] = t % 2;

      s += gg[i][j];
    }
  }

  REP(i, 0, 2)
  {
    REP(j, 0, 2)
    {
      g[i][j] = gg[i][j];
    }
  }

  return s;
}

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif

  int n, i = -1;
  char ch;
  scanf("%d\n\n", &n);

  REP(ii, 1, n)
  {
    i = -1;

    REP(k, 0, 2)
    {
      REP(j, 0, 2)
      {
        scanf("%c", &ch);
        g[k][j] = ch - 48;
        i += g[k][j];
      }
      scanf("\n");
    }

    if (i > -1)
    {
      i = 0;
    }

    // REP(k, 0, 2)
    // {
    //   REP(j, 0, 2)
    //   {
    //     printf("%d", g[k][j]);
    //   }
    //   printf("\n");
    // }
    // printf("\n*****************\n");

    while (f() > 0)
    {
      // REP(k, 0, 2)
      // {
      //   REP(j, 0, 2)
      //   {
      //     printf("%d", g[k][j]);
      //   }
      //   printf("\n");
      // }
      // printf("\n*****************\n");

      i++;
    }

    printf("%d\n", i);
  }

  return 0;
}