#include <iostream>

using namespace std;

int main() {
  int t;
  long long b, w, x, y, z, c;

  cin>>t;
  for (int i=0; i<t; i++) {
    cin>>b>>w;
    cin>>x>>y>>z;

    if (x>y+z) {
      x = y + z;
    } else if (y>x+z) {
      y = x + z;
    }

    cout<<x*b+y*w<<endl;
  }

  return 0;
}
