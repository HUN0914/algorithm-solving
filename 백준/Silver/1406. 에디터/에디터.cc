#include <bits/stdc++.h>

using namespace std;
list<char>li;
auto t = li.begin();
string word;

void solve() {

	for (int i = 0; i < word.size(); i++)
	{
		li.insert(t,word[i]);
	}

	int n;
	char mj;
	cin >> n;
	while (n--)
	{
		cin >> mj;

		if (mj == 'L')
		{
			if (t != li.begin())
			{
				t--;
			}

		}
		else if (mj == 'D')
		{
			if (t != li.end()) {
				t++;
			}

		}
		else if (mj == 'B')
		{
			if (t != li.begin())
			{
				t = li.erase(--t);
			}

		}
		else if (mj == 'P')
		{
			char ww;
			cin >> ww;

			li.insert(t, ww);

		}

	}

	for (auto i : li)
	{
		cout << i;
	}
}

int main(void)
{
    ios::sync_with_stdio(false);
	cin >> word;
	solve();

	return 0;
}