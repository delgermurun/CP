#include <iostream>

using namespace std;

int main() {
  int n;
  char m[100][100];

  cin>>n;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      cin>>m[i][j];
    }
  }

  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (i==0 or j==0 or i==n-1 or j==n-1) {
        cout<<m[i][j];
        continue;
      }

      if (m[i][j] > m[i-1][j] and m[i][j] > m[i][j-1] and
          m[i][j] > m[i+1][j] and m[i][j] > m[i][j+1]) {
        cout<<'X';
        continue;
      }

      cout<<m[i][j];
    }
    cout<<endl;
  }

  return 0;
}
