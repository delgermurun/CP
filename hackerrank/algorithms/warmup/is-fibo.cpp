#include <iostream>
#include <set>

using namespace std;

int main() {
  long long int t, n, i, f1=0, f2=1, f3=1;
  set <long long int> f;
  f.insert(1);

  cin>>t;
  for (i = 0; i < t; i++) {
    cin>>n;
    while (n>f3) {
      f3 = f1 + f2;
      f1 = f2;
      f2 = f3;
      f.insert(f3);
    }

     if (f.find(n) == f.end())
       cout<<"IsNotFibo"<<endl;
     else 
       cout<<"IsFibo"<<endl;
  }
  return 0;
}
