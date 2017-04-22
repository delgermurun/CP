// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=611&page=show_problem&problem=1256

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int cardmap[128];

void createCardMap()
{
  for(char c = '2'; c<='9'; c++) {
    cardmap[c] = c-'0';
  }

  cardmap['T'] = 10;
  cardmap['J'] = 11;
  cardmap['Q'] = 12;
  cardmap['K'] = 13;
  cardmap['A'] = 14;
}

int main() {
  createCardMap();

  string line;
  char b[5][2], w[5][2];

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

  while (getline(cin, line)) {
    for (int i = 0; i < 13; i += 3)
    {
      b[i / 3][0] = line[i];
      b[i / 3][1] = line[i + 1];
    }

    for (int i = 15; i < 28; i += 3)
    {
      w[i / 3 - 5][0] = line[i];
      w[i / 3 - 5][1] = line[i + 1];
    }
  }

  return 0;
}
