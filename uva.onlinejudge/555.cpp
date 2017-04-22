// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=611&page=show_problem&problem=496

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

// ‘C’, ‘D’, ‘S’, ‘H’
bool is_big(int p[85], char card1[2], char card2[2]) {
  int p1 = p[card1[0]] + p[card1[1]];
  int p2 = p[card2[0]] + p[card2[1]];

  return p1 > p2;
}

/*
S: C3 C5 C7 CT CJ D9 DT DJ S3 SK H2 H9 HT
W: C2 C4 CK D4 D5 D6 DQ DA S4 S8 ST SJ H8
N: C6 C8 C9 CA D8 S9 SA H4 H5 H6 H7 HJ HA
E: CQ D2 D3 D7 DK S2 S5 S6 S7 SQ H3 HQ HK
*/

void sort_card(int p[85], char cards[13][2]) {
  char t;
  for (int i = 0; i < 12; ++i)
  {
    for (int j = i + 1; j < 13; ++j)
    {
      //cout<<cards[j]<<" "<<cards[i]<<endl;
      //continue;

      if (is_big(p, cards[i], cards[j])) {
        t = cards[i][0];
        cards[i][0] = cards[j][0];
        cards[j][0] = t;

        t = cards[i][1];
        cards[i][1] = cards[j][1];
        cards[j][1] = t;
      }
    }
  }
}

// S, W, N, E
void print_deck(char cards[4][13][2]) {
  cout<<"S:";
  for (int i = 0; i < 13; ++i)
  {
    cout<<" "<<cards[0][i][0]<<cards[0][i][1];
  }
  cout<<endl;

  cout<<"W:";
  for (int i = 0; i < 13; ++i)
  {
    cout<<" "<<cards[1][i][0]<<cards[1][i][1];
  }
  cout<<endl;

  cout<<"N:";
  for (int i = 0; i < 13; ++i)
  {
    cout<<" "<<cards[2][i][0]<<cards[2][i][1];
  }
  cout<<endl;

  cout<<"E:";
  for (int i = 0; i < 13; ++i)
  {
    cout<<" "<<cards[3][i][0]<<cards[3][i][1];
  }
  cout<<endl;
}

int main() {
  char cards[4][13][2];
  int t;

  int p[85];

  p['A'] = 14;
  p['K'] = 13;
  p['Q'] = 12;
  p['J'] = 11;
  p['T'] = 10;
  p['9'] = 9;
  p['8'] = 8;
  p['7'] = 7;
  p['6'] = 6;
  p['5'] = 5;
  p['4'] = 4;
  p['3'] = 3;
  p['2'] = 2;

  p['H'] = 400;
  p['S'] = 300;
  p['D'] = 200;
  p['C'] = 100;

  string line;

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

  getline(cin, line);

  while (line[0] != '#') {
    switch (line[0]) {
      case 'S':
        t = 0;
        break;
      case 'W':
        t = 1;
        break;
      case 'N':
        t = 2;
        break;
      case 'E':
        t = 3;
        break;
    }

    getline(cin, line);
    for (int i = 0; i < line.length(); i += 2)
    {
      t = (t + 1) % 4;

      cards[t][i/8][0] = line[i];
      cards[t][i/8][1] = line[i+1];
    }

    getline(cin, line);
    for (int i = 0; i < line.length(); i += 2)
    {
      t = (t + 1) % 4;

      cards[t][(52 + i)/8][0] = line[i];
      cards[t][(52 + i)/8][1] = line[i+1];
    }

    //print_deck(cards);
    //cout<<"**********"<<endl;
    for (int i = 0; i < 4; ++i)
    {
      sort_card(p, cards[i]);
    }

    print_deck(cards);

    getline(cin, line);
  }

  return 0;
}
