// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=611&page=show_problem&problem=1146

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

void init_cards(string cards[53])
{
  string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
  string values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

  int count = 0;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 13; j++)
      cards[count++] = values[j] + " of " + suits[i];
  }
}

int main() {
  string cards[52];
  init_cards(cards);

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

  int t, n, shuffle_number;
  int deck1[52], deck2[52];
  int shuffle[100][52];
  char buffer [10];

  scanf("%d", &t);

  for (int i = 0; i < t; ++i)
  {
    scanf("%d", &n);
    for (int j = 0; j < n; ++j)
    {
      for (int l = 0; l < 52; ++l)
      {
        scanf("%d", &shuffle[j][l]);
      }
    }

    for (int l = 0; l < 52; ++l)
    {
      deck1[l] = l;
    }
    fgets(buffer, 10, stdin);
    while (fgets(buffer, 10, stdin) != NULL && buffer[0] != '\n')
    {
      shuffle_number = atoi(buffer);
      for (int j = 0; j < 52; j++) {
        deck2[j] = deck1[shuffle[shuffle_number-1][j] - 1];
      }

      for (int j = 0; j < 52; j++) {
        deck1[j] = deck2[j];
      }
    }

    if (i > 0) {
      cout<<endl;
    }
    for (int j = 0; j < 52; j++) {
      cout << cards[deck1[j]] << endl;
    }
  }

  return 0;
}
