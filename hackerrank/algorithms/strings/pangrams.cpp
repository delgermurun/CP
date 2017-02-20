#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
  int j, l, c, k;
  short s[26] = {0};
  char ch[1000];

  cin.getline(ch,sizeof(ch));

  j = 0;
  c = 0;

  while (c < 26 && ch[j] != '\0') {
    k = ch[j];
    if (k > 64 && k < 123 && (k > 96 || k < 91)) {
      if (k>96) {
        k -= 97;
      } else {
        k -= 65;
      }

      if (s[k] == 0) {
        c++;
        s[k] = 1;
      }
    }
    j++;
  }

  if (c == 26) {
    cout<<"pangram"<<endl;
  } else {
    cout<<"not pangram"<<endl;
  }

  return 0;
}
