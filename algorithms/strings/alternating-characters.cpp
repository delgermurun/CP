#include <iostream>

using namespace std;

int main() {
  int t;
  char ch[100000];

  cin>>t;
  for (int i=0;i<t;i++) {
    cin>>ch;
    int j = 0;
    int c = 0;
    char pre = ch[0];

    while (ch[j] != '\0') {
      j++;
      if (pre == ch[j]) {
        c++;
      } else {
        pre = ch[j];
      }
    }
    cout<<c<<endl;
  }

  return 0;
}
