#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, c, i;
  int a[1000];

  cin>>n;
  for (i=0;i<n;i++) {
    cin>>a[i];
  }

  sort(a, a+n);

  c = n;
  while (c > 0) {
    cout<<c<<endl;

    c--;
    i = n-c;
    while (a[i] == a[n-c-1] and i<n) {
      c--;
      i++;
    }
  }

  return 0;
}
