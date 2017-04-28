// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=615&page=show_problem&problem=1886

#include "iostream"
#include "string"

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	string s, line;
	bool isP;

	while (getline(cin, line), line.compare("DONE") != 0) {
		s = "";
		for (int i = 0; i < line.length(); ++i)
		{
			if (line[i] == ' ' || line[i] == '.' || line[i] == '!'
				|| line[i] == ',' || line[i] == '?') {
				continue;
			}

			if (line[i] > 96) {
				line[i] -= 32;
			}

			s += line[i];
		}

		isP = true;

		for (int i = 0; i < s.length() / 2 + s.length() % 2; ++i)
		{
			if (s[i] != s[s.length()-i-1]) {
				isP = false;
				break;
			}
		}

		if (isP) {
			printf("You won't be eaten!\n");
		} else {
			printf("Uh oh..\n");
		}
	}
	return 0;
}
