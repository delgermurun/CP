// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=612&page=show_problem&problem=637

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
  int x, y, t;

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

  while (cin>>x,cin>>y,x > 0 || y > 0) {
    if (x < 2 || y < 2 || (x < 3 && y < 3)) {
      printf("%d knights may be placed on a %d row %d column board.\n", x * y, x, y);
      continue;
    }

    if (x == 2 || y == 2) {
      if (x == 2) {
        t = (y / 4) * 4;
        if (y % 4 != 3) {
          t += (y % 4) * 2;
        } else {
          t += 4;
        }
      } else {
        t = (x / 4) * 4;
        if (x % 4 != 3) {
          t += (x % 4) * 2;
        } else {
          t += 4;
        }
      }

      printf("%d knights may be placed on a %d row %d column board.\n", t, x, y);
      continue;
    }

    printf("%d knights may be placed on a %d row %d column board.\n", ((x * y) + ((y * x) % 2)) / 2, x, y);
  }

  return 0;
}
