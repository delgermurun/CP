#include <iostream>
#include <algorithm>

using namespace std;

int find_path(int p[500000][2], int * r, int n, int m, int reached_node_count) {
  int c = 0;
  int pp[n+1][2];
  int pn[n+1] = {};

  for (int i=0; i<m; i++) {
    if (r[p[i][0]] != -1 && r[p[i][1]] == -1 && pn[p[i][1]] == 0) {
      pn[p[i][1]] = 1;
      pp[c][0] = p[i][1];
      pp[c][1] = r[p[i][0]] + 6;
      c++;
      if (reached_node_count + c == n) {
        break;
      }
    } else if (r[p[i][1]] != -1 && r[p[i][0]] == -1 && pn[p[i][0]] == 0) {
      pn[p[i][0]] = 1;
      pp[c][0] = p[i][0];
      pp[c][1] = r[p[i][1]] + 6;

      c++;
      if (reached_node_count + c == n) {
        break;
      }
    }
  }

  for (int i=0; i<c; i++) {
    r[pp[i][0]] = pp[i][1];
  }

  return c;
}

void solve(int n, int m, int p[500000][2], int s) {
  int r[n+1];
  fill_n(r, n+1, -1);

  r[s] = 0;

  int reached_node_count = 1;
  int result;
  do {
    result = find_path(p, r, n, m, reached_node_count);
    reached_node_count += result;
  } while (reached_node_count < n && result != 0);

  for (int j=1;j<n;j++) {
    if (j != s) {
      cout<<r[j]<<" ";
    }
  }
  cout<<r[n]<<endl;
}

int main() {
  int t, n, m, s;
  int p[500000][2];

  cin>>t;
  for (int i=0;i<t;i++) {
    cin>>n>>m;
    for (int j=0;j<m;j++) {
      cin>>p[j][0]>>p[j][1];
    }
    cin>>s;

    solve(n, m, p, s);
  }

  return 0;
}
