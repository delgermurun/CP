// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=611&page=show_problem&problem=3399

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
  int a, b, c, a1=1, b1=1, c1=1, x, y, m, g;

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

  while (cin>>a,cin>>b,cin>>c,cin>>x,cin>>y, a > 0) {
    m = 0;
    a1 = 1;
    b1 = 1;
    c1 = 1;

    if (a > b) {
      m = a;
      a = b;
      b = m;
    }

    if (a > c) {
      m = a;
      a = c;
      c = m;
    }

    if (b > c) {
      m = b;
      b = c;
      c = m;
    }

    if (x > y) {
      m = x;
      x = y;
      y = m;
    }

    m = 0;

    if (y < a) {
      a1 = 0;
      m++;
    } else if (y < b) {
      b1 = 0;
      m++;
    } else if (y < c) {
      c1 = 0;
      m++;
    }

    if (a1 > 0 && x < a) {
      a1 = 0;
      m++;
    } else if (b1 > 0 && x < b) {
      b1 = 0;
      m++;
    } else if (c1 > 0 && x < c) {
      c1 = 0;
      m++;
    }

    if (m > 1) {
      printf("-1\n");
      continue;
    }

    if (m == 0) {
      m = 1;
      while (m == a || m == b || m == c || m == x || m == x) {
        m++;
      }
      printf("%d\n", m);
    } else {
      if (c1 > 0) {
        m = c + 1;
      } else {
        m = b + 1;
      }

      while (m == a || m == b || m == c || m == x || m == y) {
        m++;
      }

      if (m > 52) {
        printf("-1\n");
      } else {
        printf("%d\n", m);
      }
    }
  }

  return 0;
}
