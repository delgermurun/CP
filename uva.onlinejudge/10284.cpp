// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=612&page=show_problem&problem=1225

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void occupy(char b[8][8], int r, int c) {
  if (b[r][c] == 'p') {
    if (r < 7 && c < 7 && b[r+1][c+1] == '*') {
      b[r+1][c+1] = 'x';
    }

    if (r < 7 && c > 0 && b[r+1][c-1] == '*') {
      b[r+1][c-1] = 'x';
    }

    return;
  }

  if (b[r][c] == 'P') {
    if (r > 0 && c < 7 && b[r-1][c+1] == '*') {
      b[r-1][c+1] = 'x';
    }

    if (r > 0 && c > 0 && b[r-1][c-1] == '*') {
      b[r-1][c-1] = 'x';
    }

    return;
  }

  if (b[r][c] == 'k' || b[r][c] == 'K') {
    if (r + 1 < 8 && b[r+1][c] == '*') {
      b[r+1][c] = 'x';
    }

    if (r + 1 < 8 && c + 1 < 8 && b[r+1][c+1] == '*') {
      b[r+1][c+1] = 'x';
    }

    if (r + 1 < 8 && c - 1 > -1 && b[r+1][c-1] == '*') {
      b[r+1][c-1] = 'x';
    }

    if (r - 1 > -1 && b[r-1][c] == '*') {
      b[r-1][c] = 'x';
    }

    if (r - 1 > -1 && c + 1 < 8 && b[r-1][c+1] == '*') {
      b[r-1][c+1] = 'x';
    }

    if (r - 1 > -1 && c - 1 > -1 && b[r-1][c-1] == '*') {
      b[r-1][c-1] = 'x';
    }

    if (c - 1 > -1 && b[r][c-1] == '*') {
      b[r][c-1] = 'x';
    }

    if (c + 1 < 8 && b[r][c+1] == '*') {
      b[r][c+1] = 'x';
    }

    return;
  }

  if (b[r][c] == 'n' || b[r][c] == 'N') {
    if (r + 1 < 8 && c + 2 < 8 && b[r+1][c+2] == '*') {
      b[r+1][c+2] = 'x';
    }

    if (r - 1 > -1 && c + 2 < 8 && b[r-1][c+2] == '*') {
      b[r-1][c+2] = 'x';
    }

    if (r + 2 < 8 && c + 1 < 8 && b[r+2][c+1] == '*') {
      b[r+2][c+1] = 'x';
    }

    if (r + 2 < 8 && c - 1 > -1 && b[r+2][c-1] == '*') {
      b[r+2][c-1] = 'x';
    }

    if (c + 1 < 8 && r - 2 > -1 && b[r-2][c+1] == '*') {
      b[r-2][c+1] = 'x';
    }

    if (c - 1 > -1 && r - 2 > -1 && b[r-2][c-1] == '*') {
      b[r-2][c-1] = 'x';
    }

    if (c - 2 > -1 && r + 1 < 8 && b[r+1][c-2] == '*') {
      b[r+1][c-2] = 'x';
    }

    if (c - 2 > -1 && r - 1 > -1 && b[r-1][c-2] == '*') {
      b[r-1][c-2] = 'x';
    }

    return;
  }

  if (b[r][c] == 'r' || b[r][c] == 'R' || b[r][c] == 'q' || b[r][c] == 'Q') {
    for (int i = c+1; i < 8; ++i)
    {
      if (b[r][i] == '*' || b[r][i] == 'x') {
        b[r][i] = 'x';
      } else {
        break;
      }
    }

    for (int i = c-1; i > -1; --i)
    {
      if (b[r][i] == '*' || b[r][i] == 'x') {
        b[r][i] = 'x';
      } else {
        break;
      }
    }

    for (int i = r+1; i < 8; ++i)
    {
      if (b[i][c] == '*' || b[i][c] == 'x') {
        b[i][c] = 'x';
      } else {
        break;
      }
    }

    for (int i = r-1; i > -1; --i)
    {
      if (b[i][c] == '*' || b[i][c] == 'x') {
        b[i][c] = 'x';
      } else {
        break;
      }
    }
  }

  if (b[r][c] == 'b' || b[r][c] == 'B' || b[r][c] == 'q' || b[r][c] == 'Q') {
    int i = r; int j = c;
    while (i++, j++, i < 8 && j < 8)
    {
      if (b[i][j] == '*' || b[i][j] == 'x') {
        b[i][j] = 'x';
      } else {
        break;
      }
    }

    i = r; j = c;
    while (i++, j--, i < 8 && j > -1)
    {
      if (b[i][j] == '*' || b[i][j] == 'x') {
        b[i][j] = 'x';
      } else {
        break;
      }
    }

    i = r; j = c;
    while (i--, j++, i > -1 && j < 8)
    {
      if (b[i][j] == '*' || b[i][j] == 'x') {
        b[i][j] = 'x';
      } else {
        break;
      }
    }

    i = r; j = c;
    while (i--, j--, i > -1 && j > -1)
    {
      if (b[i][j] == '*' || b[i][j] == 'x') {
        b[i][j] = 'x';
      } else {
        break;
      }
    }

    return;
  }
}

int main() {
  int r, c, p;
  char b[8][8];
  string line;

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

  while (getline(cin, line)) {
    r = 0; c = 0; p = 0;
    for (int i = 0; i < 8; ++i)
    {
      for (int j = 0; j < 8; ++j)
      {
        b[i][j] = '*';
      }
    }

    for (int i = 0; i < line.length(); ++i)
    {
      if (line[i] == '/') {
        r++;
        c = 0;
        continue;
      }

      if (line[i] > 48 && line[i] < 57) {
        c += line[i] - 48;
      } else {
        b[r][c] = line[i];
        c++;
      }
    }

    /*for (int i = 0; i < 8; ++i)
    {
      for (int j = 0; j < 8; ++j)
      {
        cout<<b[i][j];
      }
      cout<<endl;
    }
    cout<<endl;
    */

    for (int i = 0; i < 8; ++i)
    {
      for (int j = 0; j < 8; ++j)
      {
        if (b[i][j] != '*' && b[i][j] != 'x') {
          occupy(b, i, j);
        }
      }
    }

    for (int i = 0; i < 8; ++i)
    {
      for (int j = 0; j < 8; ++j)
      {
        //cout<<b[i][j];
        if (b[i][j]== '*') {
          p++;
        }
      }
      //cout<<endl;
    }
    cout<<p<<endl;
  }

  return 0;
}
