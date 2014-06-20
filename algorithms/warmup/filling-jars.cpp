#include <iostream>

using namespace std;

int main() {
  long long int n, m, a, b, k, i, sum=0;

  cin>>n>>m;
  for (i=0; i<m; i++) {
    cin>>a>>b>>k;
    sum += (b-a+1)*k;
  }
  cout<<sum/n<<endl;
  return 0;
}
