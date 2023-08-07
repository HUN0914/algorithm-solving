#define _CRT_SECURE_NO_WARNINGS
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;



int main() {

	long long dp[101] = { 0, };
	int t;
	int n;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;

	cin >> t;

	

	for (int i = 0; i < t; i++)
	{
		cin >> n;

		if (n <= 4)
		{
			cout << dp[n - 1]<<"\n";
		}
		else
		{
			if (dp[n - 1] == 0)
			{
				for (int j = 4; j < n; j++)
				{
					dp[j] = dp[j - 2] + dp[j - 3];
				}

				cout << dp[n - 1]<<"\n";
			}
			else
			{
				cout << dp[n - 1]<<"\n";
			}
		}




	}


	return 0;

}

