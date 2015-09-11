#include <iostream>

using namespace std;

int main() {
  int n, k, c;
  int cha = (int)'a', chz = (int)'z', chA = (int)'A', chZ = (int)'Z';
  char a[100];

  cin>>n;
  for (int i=0;i<n;i++) {
    cin>>a[i];
  }
  cin>>k;
  k = k % 26;

  for (int i=0;i<n;i++) {
    c = (int)a[i];

    if (cha <= c and c <= chz) {
      c += k;

      if (chz < c) {
        c = c - chz;
        c = c + cha - 1;
      }
    } else if (chA <= c and c <= chZ) {
      c += k;

      if (chZ < c) {
        c = c - chZ;
        c = c + chA - 1;
      }
    }
    cout<<(char)c;
  }

  cout<<endl;
  return 0;
}
