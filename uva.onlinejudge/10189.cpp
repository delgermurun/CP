// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=613&page=show_problem&problem=1130

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

	int n, m, c, t = 0;
	char b[102][102];

	while (scanf("%d %d\n", &n, &m), n>0) {
		t++;
		for (int i = 0; i < n + 2; ++i)
		{
			b[i][0] = '.';
			b[i][m+1] = '.';
		}

		for (int i = 0; i < m + 2; ++i)
		{
			b[0][i] = '.';
			b[n+1][i] = '.';
		}

		for (int i = 1; i < n + 1; ++i)
		{
			for (int j = 1; j < m + 1; ++j)
			{
				cin>>b[i][j];
			}
		}

		for (int i = 1; i < n + 1; ++i)
		{
			for (int j = 1; j < m + 1; ++j)
			{
				c = 0;
				if (b[i][j] == '*') { continue; }

		    if (b[i+1][j] == '*') {
		    	c++;
		    }

		    if (b[i+1][j+1] == '*') {
		    	c++;
		    }

		    if (b[i+1][j-1] == '*') {
		    	c++;
		    }

		    if (b[i-1][j] == '*') {
		    	c++;
		    }

		    if (b[i-1][j+1] == '*') {
		    	c++;
		    }

		    if (b[i-1][j-1] == '*') {
		    	c++;
		    }

		    if (b[i][j-1] == '*') {
		    	c++;
		    }

		    if (b[i][j+1] == '*') {
		    	c++;
		    }

		    b[i][j] = 48 + c;
			}
		}

		if (t > 1) {
			printf("\n");
		}

		printf("Field #%d:\n", t);

		for (int i = 1; i < n + 1; ++i)
		{
			for (int j = 1; j < m + 1; ++j)
			{
				printf("%c", b[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
