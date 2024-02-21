#include <iostream>
#include <algorithm>
#include <vector>
//Git 참고//
using namespace std;

int dp[10001];
int t;
int arr[10001];
int maxing = 0;

void solve()
{	dp[1] = arr[1];
	dp[2] = dp[1]+arr[2];

	for (int i = 3; i <= t; i++)
	{
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], max(dp[i - 1], dp[i - 2] + arr[i]));
	}

	cout << dp[t];
}

int main(void)
{
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cin >> arr[i];
	}
	solve();

	return 0;
}