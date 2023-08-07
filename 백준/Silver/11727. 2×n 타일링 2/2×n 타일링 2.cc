#define _CRT_SECURE_NO_WARNINGS
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	int dp[1001] = { 0, };
	int n;

	cin >> n;

	dp[1] = 1;
	dp[2] = 3;

	if (n < 3)
	{
		cout << dp[n];
	}
	else
	{

		for (int i = 3; i <= n; i++)
		{
			dp[i] =( dp[i - 1] + 2 * dp[i - 2])%10007;
		}
		cout << dp[n];
	}



	return 0;

}

