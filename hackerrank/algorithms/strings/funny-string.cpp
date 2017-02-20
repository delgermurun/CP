#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
  int t, j, l;
  char ch[10000];
  bool funny;

  cin>>t;
  for (int i=0;i<t;i++) {
    cin>>ch;
    funny = true;

    j = 1;
    l = strlen(ch);
    while (funny && ch[j] != '\0') {
      if (abs(ch[j]-ch[j-1]) != abs(ch[l-j-1]-ch[l-j])) {
        funny = false;
      }

      j++;
    }

    if (funny) {
      cout<<"Funny"<<endl;
    } else {
      cout<<"Not Funny"<<endl;
    }
  }

  return 0;
}
