#include <bits/stdc++.h>

using namespace std;

long long n;
long long dp[101][11];
long long result;

void solve(long long n)
{
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9)
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
				dp[i][j] %= 1000000000;

			}
		}
	}

	for (int k = 0; k < 10; k++)
		result= (result+dp[n][k]) % 1000000000;

	cout << result;
}

int main(void)
{
	ios::sync_with_stdio(false);

	cin >> n;
	solve(n);


	return 0;
}