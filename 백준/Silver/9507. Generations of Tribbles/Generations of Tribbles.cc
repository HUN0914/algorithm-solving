#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

long long fibo(int n)
{
	//long long sum;
	long long dp[68] = { 0, };

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	if (n <= 3)
	{
		return dp[n];
	}
	else
	{
		for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
		}
		return dp[n];
	}


}


int main(void)
{
	int t;
	int val;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> val;
		cout<<fibo(val)<<"\n";

	}

	return 0;
}