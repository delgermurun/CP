#include <iostream>

using namespace std;

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  long n, a, b, x, y;

  scanf("%ld\n", &n);

  for (int i = 0; i < n; ++i)
  {
    scanf("%ld %ld\n", &a, &b);
    //printf("DDDD: %ld %ld %ld\n", a, b, a+b);

    if ((a + b) % 2 != 0) {
      printf("impossible\n");
      continue;
    }

    x = (a + b) / 2;
    y = a - x;

    if (x > -1 && y > -1) {
      printf("%ld %ld\n", x, y);
    } else {
      printf("impossible\n");
    }
  }

  return 0;
}
