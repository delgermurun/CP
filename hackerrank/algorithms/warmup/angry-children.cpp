#include <iostream>

using namespace std;

// The partition function
int partition(int* input, int p, int r)
{
  int pivot = input[r];

  while ( p < r )
  {
    while ( input[p] < pivot )
      p++;

    while ( input[r] > pivot )
      r--;

    if ( input[p] == input[r] )
      p++;
    else if ( p < r )
    {
      int tmp = input[p];
      input[p] = input[r];
      input[r] = tmp;
    }
  }

  return r;
}

// The quicksort recursive function
void quicksort(int* input, int p, int r)
{
    if ( p < r )
    {
        int j = partition(input, p, r);        
        quicksort(input, p, j-1);
        quicksort(input, j+1, r);
    }
}

int main() {
  int n, k, ans, t;

  cin >> n >> k;
  int c[n];
  
  for (int i=0; i<n; i++)
    cin >> c[i];

  quicksort(c, 0, n-1);
  ans = c[n-1];
  for (int i=0; i<n-k; i++) {
    if (ans>c[i+k-1]-c[i])
      ans = c[i+k-1]-c[i];
  }

  cout<<ans<<endl;
  return 0;
}
