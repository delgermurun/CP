#include "iostream"
#include "algorithm"

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	string line, w, W;
	string words[1000], words2[1000];
	char t;
	int n = 0;

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
				for (int j = 0; j < W.length() - 1; ++j)
				{
					for (int l = j + 1; l < W.length(); ++l)
					{
						//cout<<W[j]<<" "<<W[l]<<" "<<(W[j]>W[l])<<endl;
						if (W[j] > W[l]) {
							t = W[j];
							W[j] = W[l];
							W[l] = t;
						}
					}
				}

				words[n] = w;
				words2[n] = W;
				n++;
				w = "";
				W = "";
			}
		}

		if (w.length() > 0) {
			for (int j = 0; j < W.length() - 1; ++j)
			{
				for (int l = j + 1; l < W.length(); ++l)
				{
					//cout<<W[j]<<" "<<W[l]<<" "<<(W[j]>W[l])<<endl;
					if (W[j] > W[l]) {
						t = W[j];
						W[j] = W[l];
						W[l] = t;
					}
				}
			}

			words[n] = w;
			words2[n] = W;
			n++;
			w = "";
			W = "";
		}
	}

	cout<<n<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<words2[i]<<endl;
	}

	return 0;
}
