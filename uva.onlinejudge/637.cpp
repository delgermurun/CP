#include <iostream>

using namespace std;

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  #endif

  int n, t, k, b, f;

  while (scanf("%d\n", &n), n > 0) {
    t = n;
    if (n % 4 != 0) {
      t += 4 - n % 4;
    }

    printf("Printing order for %d pages:\n", n);

    for (int i = 1; i <= t / 2; ++i) {
      k = i / 2 + i % 2;

      if (i > n && t - i + 1 > n) {
        continue;
      }

      printf("Sheet %d, ", k);

      if (i % 2 == 0) {
        printf("back : ");
        f = i;
        b = t - i + 1;
      } else {
        printf("front: ");

        b = i;
        f = t - i + 1;
      }

      if (f > n) {
        printf("Blank, ");
      } else {
        printf("%d, ", f);
      }

      if (b > n) {
        printf("Blank\n");
      } else {
        printf("%d\n", b);
      }
    }
  }

  return 0;
}
