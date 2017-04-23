// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=611&page=show_problem&problem=2166

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
  int n, t, oudlers;
  double score, rScore;
  string card;

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d\n", &t);
    oudlers = 0;
    score = 0;

    for (int j = 0; j < t; ++j)
    {
      getline(cin, card);

      if (card == "one of trumps" || card == "twenty-one of trumps" || card == "fool") {
        oudlers++;
        score += 4.5;
      } else if (card.substr(0, 4) == "king") {
        score += 4.5;
      } else if (card.substr(0, 5) == "queen") {
        score += 3.5;
      } else if (card.substr(0, 6) == "knight") {
        score += 2.5;
      } else if (card.substr(0, 4) == "jack") {
        score += 1.5;
      } else {
        score += 0.5;
      }
    }

    switch (oudlers) {
      case 0:
        rScore = 56;
        break;
      case 1:
        rScore = 51;
        break;
      case 2:
        rScore = 41;
        break;
      case 3:
        rScore = 36;
        break;
    }

    if (i > 0) {
      printf("\n");
    }
    printf("Hand #%d\n", i + 1);

    if (rScore > score) {
      printf("Game lost by %d point(s).\n", int(rScore - score));
    } else {
      printf("Game won by %d point(s).\n", int(score - rScore));
    }
  }

  return 0;
}
