#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int val1, val2;
string word;

void solve()
{
	int zero_count = 0;

	for (int i = val1; i <= val2; i++)
	{
		word = to_string(i);

		for (int j = 0; j < word.size(); j++)
		{
			if (word[j] == '0')
			{
				zero_count++;
			}
		}
	}
	cout << zero_count << "\n";
}

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> val1 >> val2;
		solve();
	}


	return 0;
}