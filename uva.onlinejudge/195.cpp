#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int F(char X)
{
	if (X >= 65 && X <= 90) //uppercase letter
		return 2 * (X - 65);
	else
		return 2 * (X - 97) + 1;
}

bool myfunction(char i, char j)
{
	return F(i) < F(j);
}

bool myfunction2(string i, string j)
{
	return i < j;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	string s;

	scanf("%d\n", &n);

	for (int i = 0; i < n; ++i)
	{
		getline(cin, s);
		sort(s.begin(), s.end(), myfunction);

		do
		{
			cout << s << '\n';
		} while (next_permutation(s.begin(), s.end(), myfunction));
	}
	return 0;
}
