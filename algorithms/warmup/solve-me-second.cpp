#include <iostream>

using namespace std;

int main() {
  int num1, num2;
  int sum;
  int t;
  cin >> t;

  for (int i=0;i<t;i++) {
    cin >> num1 >> num2;
    sum = num1 + num2;
    cout << sum << endl;
  }

  return 0;
}
