#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	string line, w, W;
	string words[1000], words2[1000], words3[1000];
	char t;
	int n = 0, c = 0;
	bool f;

	while(getline(cin, line), line[0] != '#') {
		w = ""; W = "";
		for (int i = 0; i < line.length(); ++i)
		{
			if (line[i] != ' ') {
				w += line[i];

				if (line[i] > 64 && line[i] < 91) {
					W += line[i] + 32;
				} else {
					W += line[i];
				}
				continue;
			}

			if (w.length() > 0) {
				sort(W.begin(), W.end());

				words[n] = w;
				words2[n] = W;
				n++;
				w = "";
				W = "";
			}
		}

		if (w.length() > 0) {
			sort(W.begin(), W.end());

			words[n] = w;
			words2[n] = W;
			n++;
			w = "";
			W = "";
		}
	}

	for (int i = 0; i < n; ++i)
	{
		f = false;
		for (int j = 0; j < n; ++j)
		{
			if (j != i && words2[i].compare(words2[j]) == 0) {
				f = true;
				break;
			}
		}

		if (!f) {
			words3[c] = words[i];
			c++;
		}
	}

	for (int i = 0; i < c - 1; ++i)
	{
		for (int j = i + 1; j < c; ++j)
		{
			if (words3[i] > words3[j]) {
				line = words3[i];
				words3[i] = words3[j];
				words3[j] = line;
			}
		}
	}

	for (int i = 0; i < c; ++i)
	{
		cout<<words3[i]<<endl;
	}

	return 0;
}
