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
  int n, u=1, l;

  cin >> n;
  int w[n];

  for (int i=0; i<n; i++) {
    cin>>w[i];
  }

  quicksort(w, 0, n-1);

  l = w[0];
  for (int i=1; i<n; i++) {
    if (l+4 < w[i]) {
      u++;
      l = w[i];
    }
  }
  cout<<u<<endl;
  return 0;
}
