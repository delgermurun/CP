// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=613&page=show_problem&problem=2454

#include <iostream>

using namespace std;

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

	int t, a, b, c, x, y;
	int g[100], p[1000000];
	bool done;

	scanf("%d\n", &t);

	for (int i = 0; i < t; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			g[j] = 0;
		}

		scanf("%d %d %d\n", &a, &b, &c);

		for (int j = 0; j < b; ++j)
		{
			scanf("%d %d\n", &x, &y);
			g[x - 1] = y;
		}

		for (int j = 0; j < a; ++j)
		{
			p[j] = 1;
		}

		done = false;
		for (int j = 0; j < c; ++j)
		{
			scanf("%d\n", &x);
			if (done) {
				continue;
			}

			y = j % a;
			p[y] += x;

			if (p[y] > 99) {
				p[y] = 100;
				done = true;
			}

			if (g[p[y] - 1] > 0) {
				p[y] = g[p[y] - 1];
			}

			if (p[y] > 99) {
				p[y] = 100;
				done = true;
			}
		}

		for (int j = 0; j < a; ++j)
		{
			printf("Position of player %d is %d.\n", j + 1, p[j]);
		}
	}

	return 0;
}
