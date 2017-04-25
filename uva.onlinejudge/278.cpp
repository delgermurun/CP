// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=612&page=show_problem&problem=214

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
  int n, x, y;
  char p;

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

  scanf("%d\n", &n);

  for (int i = 0; i < n; ++i)
  {
    scanf("%c %d %d\n", &p, &x, &y);
    switch (p) {
      case 'r':
        printf("%d\n", x > y ? y : x);
        break;
      case 'k':
        printf("%d\n", ((x * y) + ((y * x) % 2)) / 2);
        break;
      case 'Q':
        printf("%d\n", x > y ? y : x);
        break;
      case 'K':
        printf("%d\n", (x / 2 + x % 2) * (y / 2 + y % 2));
        break;
    }
  }

  return 0;
}
