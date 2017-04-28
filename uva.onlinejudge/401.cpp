// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=615&page=show_problem&problem=342

#include "iostream"
#include "string"

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string line;
	bool isP, isR;
	char r[91];

	for (int i = 0; i < 91; ++i)
	{
		r[i] = ' ';
	}

	r['A'] = 'A';
	r['E'] = '3';
	r['H'] = 'H';
	r['I'] = 'I';
	r['L'] = 'J';
	r['J'] = 'L';
	r['M'] = 'M';
	r['O'] = 'O';
	r['S'] = '2';
	r['T'] = 'T';
	r['V'] = 'V';
	r['U'] = 'U';
	r['W'] = 'W';
	r['X'] = 'X';
	r['Y'] = 'Y';
	r['Z'] = '5';
	r['1'] = '1';
	r['2'] = 'S';
	r['3'] = 'E';
	r['5'] = 'Z';
	r['8'] = '8';

	while (getline(cin, line)) {
		isP = isR = true;

		for (int i = 0; i < line.length() / 2 + line.length() % 2; ++i)
		{
			if (line[i] != line[line.length()-i-1]) {
				isP = false;
			}

			//cout<<i<<" "<<line.length()-i-1<<endl;
			//cout<<line[i]<<" "<<r[line[i]]<<" "<<line[line.length()-i-1]<<endl;
			if (r[line[i]] != line[line.length()-i-1]) {
				isR = false;
			}

			if (!isR && !isP) {
				break;
			}
		}

		if (!isR && !isP) {
			printf("%s -- is not a palindrome.\n\n", line.c_str());
		} else if (isR && isP) {
			printf("%s -- is a mirrored palindrome.\n\n", line.c_str());
		} else if (isP) {
			printf("%s -- is a regular palindrome.\n\n", line.c_str());
		} else if (isR) {
			printf("%s -- is a mirrored string.\n\n", line.c_str());
		}
	}

	return 0;
}
