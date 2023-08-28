#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int dp[1001] = { 0, };

int main(void)
{
	int n;

	cin >> n;

	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;

	for (int i = 5; i <= n; i++)
	{
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0)
		{
			dp[i] = 1;
		}
		else
		{
			dp[i] = 0;
		}
	}
	
	if (dp[n] == 1)
	{
		cout << "SK";
	}
	else
	{
		cout << "CY";
	}

	return 0;
}