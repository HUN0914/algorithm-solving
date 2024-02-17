#include <iostream>
#include <string>

//표 그리기

using namespace std;

int dp[1001][1001];
string word1, word2;

void solve()
{
	for (int i = 0; i < word1.size(); i++)
	{
		for (int j = 0; j < word2.size(); j++)
		{
			if (word1[i] == word2[j])
			{
				dp[i + 1][j + 1]=dp[i][j]+1;
			}
			else
			{
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i+1][j]);
			}
		}
	}

	cout << dp[word1.size()][word2.size()];
}

int main(void)
{
	cin >> word1 >> word2;

	solve();

	return 0;
}