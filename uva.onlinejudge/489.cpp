// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=613&page=show_problem&problem=430

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	int n, c, c2;
	string word, guess;
  set<char> f, w;

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif

	while (scanf("%d\n", &n), n != -1) {
		c = 0;
		c2 = 0;
    f.clear();
    w.clear();

		getline(cin, word);
		getline(cin, guess);

		for (int i = 0; i < word.length(); ++i)
		{
			w.insert(word[i]);
		}

		for (int i = 0; i < guess.length(); ++i) {
			if (w.count(guess[i]) != 0 && f.count(guess[i]) == 0) {
				c++;
			} else {
				if (f.count(guess[i]) == 0) {
					c2++;
				}
			}

			f.insert(guess[i]);

			if (c == w.size() || c2 == 7) {
				break;
			}
		}

		cout<<"Round "<<n<<endl;
		if (c2 == 7) {
			cout<<"You lose."<<endl;
		} else {
			if (c == w.size()) {
				cout<<"You win."<<endl;
			} else {
				cout<<"You chickened out."<<endl;
			}
		}
	}

	return 0;
}
