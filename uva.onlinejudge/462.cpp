// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=611&page=show_problem&problem=403

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

void bid(char cards[13][2]) {
  int p = 0, p2 = 0;
  int cS = 0, cH = 0, cD = 0, cC = 0;
  bool sS = false, sH = false, sD = false, sC = false;

  for (int i = 0; i < 13; i++)
  {
    // cout<<i<<" "<<cards[i][0]<<cards[i][1]<<endl;
    switch (cards[i][1]) {
      case 'S':
        cS++;
        break;
      case 'H':
        cH++;
        break;
      case 'D':
        cD++;
        break;
      case 'C':
        cC++;
        break;
    }
  }

  for (int i = 0; i < 13; i++)
  {
    switch (cards[i][0]) {
      case 'A':
        p += 4;

        switch (cards[i][1]) {
          case 'S':
            sS = true;
            break;
          case 'H':
            sH = true;
            break;
          case 'D':
            sD = true;
            break;
          case 'C':
            sC = true;
            break;
        }

        break;
      case 'K':
        p += 3;

        switch (cards[i][1]) {
          case 'S':
            if (cS == 1) {
              p--;
            }

            if (cS >= 2) {
              sS = true;
            }
            break;
          case 'H':
            if (cH == 1) {
              p--;
            }

            if (cH >= 2) {
              sH = true;
            }
            break;
          case 'D':
            if (cD == 1) {
              p--;
            }

            if (cD >= 2) {
              sD = true;
            }
            break;
          case 'C':
            if (cC == 1) {
              p--;
            }

            if (cC >= 2) {
              sC = true;
            }
            break;
        }

        break;
      case 'Q':
        p += 2;

        switch (cards[i][1]) {
          case 'S':
            if (cS <= 2) {
              p--;
            }

            if (cS >= 3) {
              sS = true;
            }
            break;
          case 'H':
            if (cH <= 2) {
              p--;
            }

            if (cH >= 3) {
              sH = true;
            }
            break;
          case 'D':
            if (cD <= 2) {
              p--;
            }

            if (cD >= 3) {
              sD = true;
            }
            break;
          case 'C':
            if (cC <= 2) {
              p--;
            }

            if (cC >= 3) {
              sC = true;
            }
            break;
        }

        break;
      case 'J':
        p += 1;

        switch (cards[i][1]) {
          case 'S':
            if (cS <= 3) {
              p--;
            }
            break;
          case 'H':
            if (cH <= 3) {
              p--;
            }
            break;
          case 'D':
            if (cD <= 3) {
              p--;
            }
            break;
          case 'C':
            if (cC <= 3) {
              p--;
            }
            break;
        }

        break;
    }
  }

  p2 = p;

  if (cC == 2) {
    p++;
  }

  if (cS == 2) {
    p++;
  }

  if (cH == 2) {
    p++;
  }

  if (cD == 2) {
    p++;
  }

  if (cC == 1) {
    p += 2;
  }

  if (cH == 1) {
    p += 2;
  }

  if (cD == 1) {
    p += 2;
  }

  if (cS == 1) {
    p += 2;
  }

  if (cC == 0) {
    p += 2;
  }

  if (cH == 0) {
    p += 2;
  }

  if (cD == 0) {
    p += 2;
  }

  if (cS == 0) {
    p += 2;
  }

  if (p < 14) {
    printf("PASS\n");
  } else if (p2 >= 16 && sS && sC && sH && sD) {
    printf("BID NO-TRUMP\n");
  } else {
    if (cS >= cH && cS >= cD && cS >= cC) {
      printf("BID S\n");
    } else if (cH >= cD && cH >= cC) {
      printf("BID H\n");
    } else if (cD >= cC) {
      printf("BID D\n");
    } else {
      printf("BID C\n");
    }
  }
}

int main() {
  char cards[13][2];
  int point;

  string line;

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

  while (getline(cin, line)) {
    //cout<<line<<endl;

    for (int i = 0; i < line.length(); i += 3)
    {
      cards[i / 3][0] = line[i];
      cards[i / 3][1] = line[i + 1];

      // cout<<i / 3<<" "<<cards[i / 3][0]<<cards[i / 3][1]<<endl;
    }

    bid(cards);
  }

  return 0;
}
