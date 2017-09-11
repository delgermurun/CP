#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
// #include <stdio.h>

using namespace std;

typedef long long ll;
// typedef vector<int> vi;
// typedef pair<int,int> pi;

// #define REP(i,a,b) for (int i = a; i <= b; i++)
// REP(i,1,n) {
//   search(i);
// }

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  // printf("%.9f\n", x);
  // solution comes here
  ll n, k;

  // scanf("%ld %ld", &n, &k);
  cin >> n >> k;
  if ((n / k) % 2 == 1)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  // printf('%ld', n);

  return 0;
}