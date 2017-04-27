// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=614&page=show_problem&problem=1384

#include <iostream>

using namespace std;

bool is_win(char x, char y) {
	if (x == y) {
		return false;
	}

	if (x == 'R') {
		if (y == 'S') {
			return true;
		}

		return false;
	}

	if (x == 'S') {
		if (y == 'P') {
			return true;
		}

		return false;
	}

	if (x == 'P') {
		if (y == 'R') {
			return true;
		}

		return false;
	}

	return false;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

	int t, r, c, n;
	char a[100][100], b[100][100];

	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i)
	{
		scanf("%d %d %d\n", &r, &c, &n);

		for (int j = 0; j < r; ++j)
		{
			for (int l = 0; l < c; ++l)
			{
				cin>>a[j][l];
				b[j][l] = a[j][l];
			}
		}

		for (int q = 0; q < n; ++q)
		{
			for (int j = 0; j < r; ++j)
			{
				for (int l = 0; l < c; ++l)
				{
					if (j > 0 && is_win(a[j][l], a[j-1][l])) {
						b[j-1][l] = a[j][l];
					}

					if (l > 0 && is_win(a[j][l], a[j][l-1])) {
						b[j][l-1] = a[j][l];
					}

					if (j < r - 1 && is_win(a[j][l], a[j+1][l])) {
						b[j+1][l] = a[j][l];
					}

					if (l < c - 1 && is_win(a[j][l], a[j][l+1])) {
						b[j][l+1] = a[j][l];
					}
				}
			}

			for (int j = 0; j < r; ++j)
			{
				for (int l = 0; l < c; ++l)
				{
					a[j][l] = b[j][l];
				}
			}
		}

		if (i > 0) {
			cout<<endl;
		}

		for (int j = 0; j < r; ++j)
		{
			for (int l = 0; l < c; ++l)
			{
				cout<<a[j][l];
			}
			cout<<endl;
		}
	}

	return 0;
}
