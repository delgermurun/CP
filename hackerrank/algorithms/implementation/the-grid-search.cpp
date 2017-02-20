#include <iostream>

using namespace std;

int main() {
  bool f;
  int T, R, C, r, c;
  char A[1000][1000];
  char a[1000][1000];

  cin>>T;

  for (int i=0; i<T; i++) {
    cin>>R>>C;
    for (int j=0; j<R; j++) {
      for (int k=0; k<C; k++) {
        cin>>A[j][k];
      }
    }

    cin>>r>>c;
    for (int j=0; j<r; j++) {
      for (int k=0; k<c; k++) {
        cin>>a[j][k];
      }
    }

    f = true;
    for (int J=0; J<R-r+1; J++) {
      for (int K=0; K<C-c+1; K++) {

        f = true;
        for (int j=0; j<r; j++) {
          for (int k=0; k<c; k++) {
            if (a[j][k] != A[J+j][K+k]) {
              f = false;
              break;
            }
          }

          if (!f) { break; }
        }

        if (f) {
          break;
        }
      }

      if (f) {
        break;
      }
    }

    if (f) {
      cout<<"YES";
    } else {
      cout<<"NO";
    }

    cout<<endl;
  }

  return 0;
}
