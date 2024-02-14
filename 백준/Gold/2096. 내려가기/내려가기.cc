#include <iostream>
#include <algorithm>

using namespace std;

int dp[3];
int after[3];
int arr[3];
int dpp[3];
int t;

void max_solve()
{
	after[0] = dp[0];
	after[1] = dp[1];
	after[2] = dp[2];
	dp[0] = arr[0] + max(after[0], after[1]);
	dp[1] = arr[1] + max(after[2], max(after[0], after[1]));
	dp[2] = arr[2] + max(after[1], after[2]);

}

void min_solve()
{
	after[0] = dpp[0];
	after[1] = dpp[1];
	after[2] = dpp[2];
	dpp[0] = arr[0] + min(after[0], after[1]);
	dpp[1] = arr[1] + min(after[2], min(after[0], after[1]));
	dpp[2] = arr[2] + min(after[1], after[2]);

}

int main(void)
{
	cin >> t;


	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[j];
		}
		max_solve();
		min_solve();

	}
	cout << max(dp[0], max(dp[1], dp[2])) << " ";
	cout << min(dpp[0], min(dpp[1], dpp[2]));




	return 0;
}