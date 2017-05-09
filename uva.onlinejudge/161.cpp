#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	int a[100], a2[100];
	int n, t;
	bool y;

	while(true) {
		n = 0;
		t = 91;

		while(scanf("%d", &a[n]), a[n] > 0) {
      a2[n] = 2 * a[n];

			if (t > a[n]) {
				t = a[n];
			}

			n++;
		}

		if (n == 0) {
			break;
		}

		while (t < 18000) {
      y = true;

			for (int i = 0; i < n; ++i) {
        if (t % a2[i] >= a[i] - 5) {
          y = false;
          break;
        }
			}

      if (y) {
        break;
      }

      t++;
		}

		if (y) {
      int h = t / 3600;
      int m = (t - h * 3600) / 60;
      int s = t - h * 3600 - m * 60;
      printf("0%d:%02d:%02d\n", h, m, s);
		} else {
			printf("Signals fail to synchronise in 5 hours\n");
		}
	}

	return 0;
}
