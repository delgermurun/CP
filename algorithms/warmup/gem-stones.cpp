#include <iostream>

using namespace std;

int main() {
  int n, ar[100][26]={}, sum, f;
  string s;

  cin>>n;
  sum = 0;

  for (int l=0; l<n; l++) {
    cin>>s;
    for (int i=0; i<s.size(); i++) {
      ar[l][s[i] - 'a']++;
    }
  }

  for (int i=0; i<26; i++) {
    f = 0;
    for (int j=0; j<n; j++) {
      if (ar[j][i] == 0) f = 1;
    }
    if (f == 0) sum++;
  }

  cout<<sum<<endl;
  return 0;
}
