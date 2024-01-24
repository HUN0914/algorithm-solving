#include <iostream>
#include <algorithm>


using namespace std;

int dp[1001];
int arr[1001];
int n;


void dpp()
{
	for (int a = 1; a <= n; a++)
	{
		dp[a] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}

		}
	}

	sort(dp, dp + n + 1);
	cout << dp[n];
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