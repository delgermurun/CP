// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=611&page=show_problem&problem=2725

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <set>

using namespace std;

int main() {
  int a, b, c, d;
  set<int> f, s;
  set<int> intersect;
  set<int>::iterator it;

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

  while (cin>>a,cin>>b, a > 0 || b > 0) {
    //cout<<a<<" "<<b<<endl;

    f.clear();
    s.clear();
    for (int i = 0; i < a; ++i)
    {
      cin>>c;
      f.insert(c);
    }

    for (int i = 0; i < b; ++i)
    {
      cin>>c;
      s.insert(c);
    }

    //cout<<f.size()<<" "<<s.size()<<endl;

    d = 0;
    if (f.size() < s.size()) {
      for (it = f.begin(); it != f.end(); ++it)
      {
        if (s.count(*it) == 0) {
          d++;
        }
      }
    } else {
      for (it = s.begin(); it != s.end(); ++it)
      {
        if (f.count(*it) == 0) {
          d++;
        }
      }
    }

    cout<<d<<endl;
  }

  return 0;
}
