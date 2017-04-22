// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=611&page=show_problem&problem=98

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

void move_card(int fromN, char fromC[], int toN, char toC[]) {
  for (int i = toN - 1; i >= 0; --i)
  {
    toC[i + fromN] = toC[i];
  }

  for (int i = 0; i < fromN; ++i)
  {
    toC[i] = fromC[fromN - i - 1];
  }
}

void print_decks(int n1, int n2, int nc, char p1[], char p2[], char cards[], int t) {
  printf("P1 (%d)%ch: ", n1+1, t == 0 ? '*' : ' ');

  for (int i = 0; i <= n1; ++i)
  {
    cout << p1[i] << " ";
  }

  cout << endl;

  printf("P2 (%d)%ch: ", n2+1, t == 1 ? '*' : ' ');

  for (int i = 0; i <= n2; ++i)
  {
    cout << p2[i] << " ";
  }

  cout << endl;

  printf("Desk (%d): ", nc+1);

  for (int i = 0; i <= nc; ++i)
  {
    cout << cards[i] << " ";
  }

  cout << endl;
  getchar();
}

int get_card_weidth(char c) {
  switch (c) {
    case 'A':
      return 4;
    case 'K':
      return 3;
    case 'Q':
      return 2;
    case 'J':
      return 1;
  }
  return 0;
}

int main() {
  char cards[52];
  char p1[52];
  char p2[52];
  char cc;

  int n1, n2, nc, t;

  string line;

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

  getline(cin, line);

  while (line[0] != '#') {
    n1 = -1;
    n2 = -1;
    nc = -1;
    t = 0;

    for (int j = 0; j < 4; j++)
    {
      for (int i = 1; i < line.length(); i += 3)
      {
        if (t == 0) {
          n1++;
          p1[n1] = line[i];
        } else {
          n2++;
          p2[n2] = line[i];
        }

        t = (t + 1) % 2;
      }

      getline(cin, line);
    }

    //printf("%d %d\n", n1, n2);

    t = 0;

    //print_decks(n1, n2, nc, p1, p2, cards, t);
    while (true) {
      if (t == 0) {
        if (n1 == -1) {
          break;
        }

        cc = p1[n1];
        n1--;
      } else {
        if (n2 == -1) {
          break;
        }

        cc = p2[n2];
        n2--;
      }

      nc++;
      cards[nc] = cc;

      //print_decks(n1, n2, nc, p1, p2, cards, t);

      if (cc != 'A' && cc != 'K' && cc != 'Q' && cc != 'J') {
        t = (t + 1) % 2;
        continue;
      }

      int j = get_card_weidth(cc);
      if (j > 0) {
        t = (t + 1) % 2;
      }

      do {
        if (j > 0) {
          if (t == 0) {
            if (n1 == -1) {
              break;
            }
            cc = p1[n1];
            n1--;
          } else {
            if (n2 == -1) {
              break;
            }
            cc = p2[n2];
            n2--;
          }

          nc++;
          cards[nc] = cc;

          j--;
        }

        //print_decks(n1, n2, nc, p1, p2, cards, t);

        int k = get_card_weidth(cc);
        if (k > 0) {
          t = (t + 1) % 2;
          j = k;
        }
      } while (j > 0);

      if (j > 0) {
        break;
      }

      /*
      if (j > 0 && t == 0 && n1 == -1) {
        break;
      }

      if (j > 0 && t == 1 && n2 == -1) {
        break;
      }
      */

      t = (t + 1) % 2;
      if (t == 0) {
        move_card(nc + 1, cards, n1 + 1, p1);
        n1 += nc + 1;
      } else {
        move_card(nc + 1, cards, n2 + 1, p2);
        n2 += nc + 1;
      }

      nc = -1;
      //print_decks(n1, n2, nc, p1, p2, cards, t);
    }

    printf("%d%3d\n", ( t ? 2 : 1 ), ( t ? n1 : n2 ) + 1);
  }

  //printf("\n");

  return 0;
}
