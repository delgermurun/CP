#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int h, m, s;
  char am[2];

  scanf("%d:%d:%d%2s", &h, &m, &s, am);

  if (h==12 and am[0] == 'A') {
    h = 0;
  } else if (am[0] == 'P' and h != 12) {
    h += 12;
  }

  printf("%02d:%02d:%02d\n", h, m, s);

  return 0;
}
