// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=614&page=show_problem&problem=1754

#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int n, m, c;
	int a[5][5], b[5][5];
	bool won;

	scanf("%d\n", &n);

	for (int i = 0; i < n; ++i)
	{
		won = false;

		for (int j = 0; j < 5; ++j)
		{
			for (int l = 0; l < 5; ++l)
			{
				b[j][l] = 0;
			}
		}
		b[2][2] = 1;
		a[2][2] = 0;

		c = 0;
		for (int j = 0; j < 2; ++j)
		{
			for (int l = 0; l < 5; ++l)
			{
				scanf("%d", &a[j][l]);
			}
		}

		scanf("%d", &a[2][0]);
		scanf("%d", &a[2][1]);
		scanf("%d", &a[2][3]);
		scanf("%d", &a[2][4]);

		for (int j = 3; j < 5; ++j)
		{
			for (int l = 0; l < 5; ++l)
			{
				scanf("%d", &a[j][l]);
			}
		}

		for (int q = 0; q < 75; ++q)
		{
			scanf("%d", &m);
			if (won) {
				continue;
			}

			c++;

			for (int j = 0; j < 5; ++j)
			{
				for (int l = 0; l < 5; ++l)
				{
					if (a[j][l] == m) {
						b[j][l] = 1;
						break;
					}
				}
			}

			if (b[0][0] + b[1][1] + b[2][2] + b[3][3] + b[4][4] == 5) {
				won = true;
				continue;
			}

			if (b[0][4] + b[1][3] + b[2][2] + b[3][1] + b[4][0] == 5) {
				won = true;
				continue;
			}

			for (int j = 0; j < 5; ++j)
			{
				if (b[j][0] + b[j][1] + b[j][2] + b[j][3] + b[j][4] == 5) {
					won = true;
					break;
				}

				if (b[0][j] + b[1][j] + b[2][j] + b[3][j] + b[4][j] == 5) {
					won = true;
					break;
				}
			}
		}

		printf("BINGO after %d numbers announced\n", c);
	}

	return 0;
}
