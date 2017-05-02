#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string line, w;
	string words[100], words2[100];
	int t, n;

	scanf("%d\n\n", &t);

	for (int l = 0; l < t; ++l)
	{
		if (l > 0) {
			cout<<"\n";
		}

		n = 0;
		while(getline(cin, line), line != "") {
			w = "";
			for (int i = 0; i < line.length(); ++i)
			{
				if (line[i] != ' ') {
					w += line[i];
				}
			}

			if (w.length() > 0) {
				sort(w.begin(), w.end());

				words[n] = line;
				words2[n] = w;
				n++;
			}
		}

		for (int i = 0; i < n-1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (words[i] > words[j]) {
					w = words[i];
					words[i] = words[j];
					words[j] = w;

					w = words2[i];
					words2[i] = words2[j];
					words2[j] = w;
				}
			}
		}

		for (int i = 0; i < n-1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (words2[i].compare(words2[j]) == 0) {
					if (words[i] > words[j]) {
						cout<<words[j]<<" = "<<words[i]<<'\n';
					} else {
						cout<<words[i]<<" = "<<words[j]<<'\n';
					}
				}
			}
		}
	}

	return 0;
}
