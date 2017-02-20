#include <iostream>

using namespace std;

int main() {
  int t, n, i, j, min;
  int w[100000];
  int sum;

  cin>>n>>t;
  for (int l=0; l<n; l++) {
    cin>>w[l];
  }

  for (int l=0; l<t; l++) {
    cin>>i>>j;
    min = 4;
    for (int k=i; k<=j; k++) {
      if (min > w[k]) min = w[k];
    }
    cout<<min<<"\n";
  }

  return 0;
}
