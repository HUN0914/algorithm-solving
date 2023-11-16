#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	long long dp[36] = { 0, };

	long long n;

	cin >> n;

	dp[0] = 1;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i] += (dp[j] * dp[i - j-1]);
		}
	}

	cout << dp[n];

	return 0;
}