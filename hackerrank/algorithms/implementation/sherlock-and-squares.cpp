#include <iostream>
#include <cmath>

using namespace std;

float sqrt(int n) {
  float low = 0.0;
  float high = (float)n+1;
  float mid;

  while ((high-low) > 0.00001) {
    mid = (low+high) / 2;
    if (mid*mid < n) {
      low = mid;
    } else {
      high = mid;
    }
  }
  return low;
}

int main() {
  int t;
  long long a, b, c, s, s2;

  cin>>t;
  for (int i=0; i<t; i++) {
    c = 0;
    cin>>a>>b;
    s = ceil(sqrt(a));
    s2 = floor(sqrt(b));

    if (s2>=s) {
      cout<<s2-s+1<<endl;
    } else {
      cout<<0<<endl;
    }
  }

  return 0;
}
