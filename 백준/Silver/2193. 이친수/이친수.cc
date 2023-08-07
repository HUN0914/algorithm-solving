#define _CRT_SECURE_NO_WARNINGS
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

int main() {

	int n;
	long long dp[100] = { 0, };

	cin >> n;

	dp[1] = 1;
	dp[2] = 1;

	if (n < 3)
	{
		cout << dp[n];
	}
	else
	{

		for (int i = 3; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		cout << dp[n];
	}


	return 0;

}

