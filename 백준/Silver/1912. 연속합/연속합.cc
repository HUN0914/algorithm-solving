#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[100001];
int a[100001];


int main(void)
{
	int n;
	vector<int>v;
	int val;


	cin >> n;


	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	dp[0] = a[0];
	int ret = a[0];


	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + a[i], a[i]);
		ret = max(dp[i], ret);


	}

	cout << ret;


	return 0;
}


