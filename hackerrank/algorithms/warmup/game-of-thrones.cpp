#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  int chars[26] = {0};
  int l=0;

  cin>>s;
  for (int i=0; i<s.length(); i++) {
    chars[(int)s[i]-97]++;
  }

  for (int i=0; i<26; i++) {
    if (chars[i] % 2 == 1) {
      l++;
    }

    if (l>1) {
      break;
    }
  }

  if (l>1) {
    cout<<"NO"<<endl;
  } else {
    cout<<"YES"<<endl;
  }

  return 0;
}
