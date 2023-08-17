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

	int n;
	int val;

	cin >> n;

	vector<long long>far;

	vector<long long> dp(n+1);

	vector<long long>pay; //값 +1개 더 있는 거

	for (int i = 0; i < n - 1; i++)
	{
		cin >> val;
		far.push_back(val);
	}


	for (int i = 0; i < n ; i++)
	{
		cin >> val;
		pay.push_back(val);
	}

	dp[0] = pay[0] * far[0];


	for (int i = 1; i < n-1; i++) //far i+1이 문제임
	{
		
		dp[i] = dp[i-1] + (min(pay[i], pay[i-1])*far[i]);
	}
	cout << dp[n - 2];

	return 0;
}