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

int al[100002];
int ar[100002];

int main()
{
  ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif

  int b, s, l, r;

  while (scanf("%d %d", &s, &b), s || b)
  {
    REP(i, 1, s)
    {
      al[i] = i - 1;
      ar[i] = i + 1;
    }

    al[1] = -1;
    ar[s] = -1;

    REP(i, 1, b)
    {
      scanf("%d %d", &l, &r);

      al[ar[r]] = al[l];

      if (al[l] != -1)
        printf("%d", al[l]);
      else
        printf("*");

      ar[al[l]] = ar[r];
      if (ar[r] != -1)
        printf(" %d\n", ar[r]);
      else
        printf(" *\n");
    }
    printf("-\n");
  }

  // printf("%.9f\n", x);
  // solution comes here
  return 0;
}