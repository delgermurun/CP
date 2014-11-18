#include <iostream>
#include <string>

using namespace std;

int main() {
  int t, c;
  string s;
  char ch;
  
  cin>>t;

  for (int i=0; i<t; i++) {
    c = 0;
    cin>>s;

    ch = s[0];
    for (int j=1; j<s.length(); j++) {
      if (ch == s[j]) {
        c++;
      } else {
        ch = s[j];
      }
    }
    cout<<c<<endl;
  }

  return 0;
}
