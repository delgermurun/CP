#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int main() {
  int rows, column, c, t;
  char ch[10][10] = {' '};
  char s[81] = {' '};

  cin>>s;
  int len = strlen(s);

  rows = floor(sqrt(len));
  column = ceil(sqrt(len));

  if (rows * column < len) {
    rows++;
  }

  c = 0;
  for (int i=0; i<rows; i++) {
    for (int j=0; j<column; j++) {
      if (c < len) {
        ch[i][j] = s[c];
      }

      c++;
    }
  }

  c = 0;
  for (int j=0; j<column; j++) {
    for (int i=0; i<rows; i++) {
      t = i * (j + 1) + j + 1;
      if (t > len) {
        continue;
      }
      cout<<ch[i][j];
      c++;
    }

    cout<<' ';
  }

  cout<<endl;
  return 0;
}
