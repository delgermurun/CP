#include <iostream>
#include <set>

using namespace std;

int main() {
  int t, n, a, b, l;

  cin>>t;
  for (int i=0; i<t; i++) {
    set <int> ans;
    cin>>n>>a>>b;
    for (int j=0; j<n; j++) {
      ans.insert(j*a + (n-j-1)*b);
    }
    for(set<int>::iterator it = ans.begin(); it != ans.end(); it++)
      cout << *it << " ";
     cout << endl;
  }
}
