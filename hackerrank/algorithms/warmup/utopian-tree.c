#include <stdio.h>

int main() {
  int n, i, t, h, j;
  scanf("%d", &t);
  for (i=0; i<t; i++) {
    scanf("%d", &n);
    h = 1;
    for (j=0; j<n; j++) {
      if (j % 2 == 1) {
        h++;
      } else {
        h *= 2;
      }
    }
    printf("%d", h);
  }
}
