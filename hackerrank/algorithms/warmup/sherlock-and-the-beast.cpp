#include <iostream>

using namespace std;

int main() {
  int t, n, m3, j;

  cin>>t;

  for (int i=0; i<t; i++) {
    cin>>n;

    if (n<3 || n==4 || n==7) {
      cout<<-1<<endl;
      continue;
    }

    if (n==3) {
      cout<<555<<endl;
      continue;
    }

    if (n==5) {
      cout<<33333<<endl;
      continue;
    }

    m3 = n % 3;
    if (m3==0) {
      for (j=0; j<n; j++) {
        cout<<5;
      }
      cout<<endl;
      continue;
    }

    if (m3==1) {
      for (j=0; j<n-10; j++) {
        cout<<5;
      }
      for (j=0; j<10; j++) {
        cout<<3;
      }
      cout<<endl;
      continue;
    }

    if (m3==2) {
      for (j=0; j<n-5; j++) {
        cout<<5;
      }
      for (j=0; j<5; j++) {
        cout<<3;
      }
      cout<<endl;
      continue;
    }
  }

  return 0;
}
