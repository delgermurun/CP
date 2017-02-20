#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int min;

  int m, n, c, r2;
  long r;
  long a[300][300];
  long b[150][900];
  long b2[150][900];
  int len[150];

  freopen("input09.txt","r",stdin);
  cin>>m>>n>>r;
  for (int i=0;i<m;i++) {
    for (int j=0;j<n;j++) {
      cin>>a[i][j];
    }
  }

  if (m < n) {
    min = m / 2;
  } else {
    min = n / 2;
  }

  for (int l=0;l<min;l++) {
    c = 0;

    for (int i=l;i<n-l;i++) {
      b[l][c] = a[l][i];
      c++;
    }

    for (int i=l+1;i<m-l;i++) {
      b[l][c] = a[i][n-l-1];
      c++;
    }

    for (int i=n-l-2;i>=l;i--) {
      b[l][c] = a[m-l-1][i];
      c++;
    }

    for (int i=m-l-2;i>l;i--) {
      b[l][c] = a[i][l];
      c++;
    }

    len[l] = c;
    continue;
  }

  /*cout<<"**********************\n";
  for (int i=0;i<min;i++) {
    for (int j=0;j<len[i];j++) {
      cout<<b[i][j]<<" ";
    }
    cout<<"\n";
  }

  return 0;*/

  for (int i=0;i<min;i++) {
    r2 = r % len[i];
    for (int j=0;j<len[i];j++) {
      b2[i][j] = b[i][(j+r2) % len[i]];
    }
  }

  for (int l=0;l<min;l++) {
    c = 0;

    for (int i=l;i<n-l;i++) {
      a[l][i] = b2[l][c];
      c++;
    }

    for (int i=l+1;i<m-l;i++) {
      a[i][n-l-1] = b2[l][c];
      c++;
    }

    for (int i=n-l-2;i>=l;i--) {
      a[m-l-1][i] = b2[l][c];
      c++;
    }

    for (int i=m-l-2;i>l;i--) {
      a[i][l] = b2[l][c];
      c++;
    }
  }

  freopen("output.txt","w",stdout);
  //cout<<"**********************\n";
  for (int i=0;i<m;i++) {
    for (int j=0;j<n;j++) {
      cout<<a[i][j]<<" ";
    }
    cout<<"\n";
  }

  return 0;
}
