#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <deque>


using namespace std;


int main(void)
{

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long sum;
	int n;
	int m;
	int val;

	int com1, com2;

	cin >> n >> m;

	vector<long long>dp(n+1);

	dp[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> val;
		dp[i] = val + dp[i - 1];
	}

	for (int i = 0; i < m; i++)
	{
		cin >> com1 >> com2;
		cout<<dp[com2] - dp[com1 - 1]<<"\n";

	}




	return 0;
}