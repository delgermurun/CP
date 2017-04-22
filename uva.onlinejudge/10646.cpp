// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=611&page=show_problem&problem=1587

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int get_value(char f) {
  if ('2' <= f && f <= '9') {
    return f - 48;
  }

  return 10;
}

int main() {
  int n, x, y, top;
  string cards[52], cards2[52];

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    y = 0;

    for (int j = 0; j < 27; ++j)
    {
      cin>>cards[j];
    }

    for (int j = 0; j < 25; ++j)
    {
      cin>>cards2[j];
    }

    top = 26;
    for (int j = 0; j < 3; ++j)
    {
      x = get_value(cards[26][0]);
      y += x;

      top -= 11 - x;
      //printf("%c%c %d %d\n", cards[26][0], cards[26][1], x, top);
    }

    //printf("%d %d\n", top, y);

    if (y - 1 <= top) {
      printf("Case %d: %s\n", i + 1, cards[y - 1].c_str());
    } else {
      printf("Case %d: %s\n", i + 1, cards2[y - top - 2].c_str());
    }
  }

  return 0;
}
