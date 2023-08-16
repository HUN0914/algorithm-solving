#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <deque>


using namespace std;

int dp[1000001] = { 0, };

int main(void)
{
	int n;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	cin >> n;

	if (n <= 3)
	{
		cout << dp[n];
	}
	else
	{

		for (int i = 4; i <= n; i++)
		{
			dp[i] = ((dp[i - 1]%15746) + (dp[i - 2]%15746))%15746;
		}

		cout << dp[n];

	}

	return 0;
}