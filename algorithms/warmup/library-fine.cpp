#include <iostream>

using namespace std;

int main() {
  int d1, m1, y1,  d2, m2, y2;
  long fine;

  cin>>d2>>m2>>y2;
  cin>>d1>>m1>>y1;

  fine = 0;
  if (y2>y1) {
    fine = 10000;
  } else if (y2 == y1 and m2>m1) {
    fine = 500 * (m2-m1);
  } else if (y2 == y1 and m2==m1 and d2>d1) {
    fine = 15 * (d2-d1);
  }

  cout<<fine<<endl;

  return 0;
}
