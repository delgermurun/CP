#include <iostream>

using namespace std;

int main() {
  int m, n, temp=0, team=0, topic=0;
  char ch;
  int a[500][500];

  cin>>n>>m;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      cin>>ch;

      if (ch == '0') {
        a[i][j] = 0;
      } else {
        a[i][j] = 1;
      }
    }
  }

  for (int i=0;i<n-1;i++) {
    for (int j=i;j<n;j++) {
      temp = 0;

      for (int k=0;k<m;k++) {
        if (a[i][k]|a[j][k] == 1) {
          temp += 1;
        }
      }

      if (temp > topic) {
        topic = temp;
        team = 1;
      } else if (temp == topic) {
        team += 1;
      }
    }
  }

  cout<<topic<<endl;
  cout<<team<<endl;

  return 0;
}
