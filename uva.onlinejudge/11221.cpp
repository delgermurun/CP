// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=615&page=show_problem&problem=2162

#include "iostream"
#include "string"

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int t, k;
	string line, line2;
	char a[100][100];
	bool no_magic;

	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i)
	{
		getline(cin, line2);
		line = "";
		k = 0;
		no_magic = false;

		for (int j = 0; j < line2.length(); ++j)
		{
			if (line2[j] > 96 && line2[j] < 123) {
				line += line2[j];
			}
		}

		while (k * k < line.length()) {
			k++;
		}

		printf("Case #%d:\n", i+1);

		if (k * k != line.length()) {
			printf("No magic :(\n");
			continue;
		}

		for (int j = 0; j < (k * k) / 2 + (k * k) % 2; ++j)
		{
			if (line[j] != line[k * k - j - 1]) {
				no_magic = true;
				break;
			}
		}

		if (no_magic) {
			printf("No magic :(\n");
			continue;
		}

		for (int j = 0; j < k; ++j) {
			for (int l = 0; l < k; ++l) {
				a[j][l] = line[j * k + l];
			}
		}

		line2 = "";
		for (int j = 0; j < k; ++j) {
			for (int l = 0; l < k; ++l) {
				line2 += a[l][j];
			}
		}

		if (line2.compare(line) != 0) {
			printf("No magic :(\n");
			continue;
		}

		for (int j = 0; j < (k * k) / 2 + (k * k) % 2; ++j)
		{
			if (line2[j] != line2[k * k - j - 1]) {
				no_magic = true;
				break;
			}
		}

		if (no_magic) {
			printf("No magic :(\n");
			continue;
		}

		printf("%d\n", k);
	}

	return 0;
}
