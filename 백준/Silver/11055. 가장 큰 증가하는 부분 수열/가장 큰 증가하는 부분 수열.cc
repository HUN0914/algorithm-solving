#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int arr[1001];
int n;

void dpp()
{

	for (int i = 1; i <= n; i++)
	{
		dp[i] = arr[i];

		for (int j = 1; j < i; j++)
		{
			if (arr[i]>arr[j]&&dp[i]<dp[j]+arr[i])
			{
				dp[i] = dp[j] + arr[i];
			}
		}
	}

	sort(dp, dp + n + 1);
	printf("%d", dp[n]);
}

int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dpp();

}