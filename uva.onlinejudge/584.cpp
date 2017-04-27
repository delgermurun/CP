// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=614&page=show_problem&problem=525

#include <iostream>

using namespace std;

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

	string line;
	int s, p, k;

	while(getline(cin, line), line[0] != 'G') {
		s = 0; p = 0; k = 0;

		//cout<<line<<endl;
		for (int i = 0; i < line.length(); i += 2)
		{
			k++;
			//cout<<line[i]<<" "<<s<<endl;
			if (line[i] == '/') {
				s += 10 - p;

				if (i + 2 < line.length()) {
					if (line[i + 2] == 'X') {
						s += 10;
					} else {
						s += line[i + 2] - 48;
					}

					if (k == 20) {
						break;
					}
				}

				continue;
			}

			if (line[i] == 'X') {
				k++;
				s += 10;

				if (i + 2 < line.length()) {
					if (line[i + 2] == 'X') {
						s += 10;
					} else {
						p = line[i + 2] - 48;
						s += p;
					}
				}

				if (i + 4 < line.length()) {
					if (line[i + 4] == 'X') {
						s += 10;
					} else if (line[i + 4] == '/') {
						s += 10 - p;
					} else {
						s += line[i + 4] - 48;
					}

					if (k == 20) {
						break;
					}
				}

				continue;
			}

			p = line[i] - 48;
			s += p;
		}

		cout<<s<<endl;
	}

	return 0;
}
