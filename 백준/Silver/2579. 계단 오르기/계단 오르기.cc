#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int main(void)
{
	int n;
	vector<int> v;
	int val;
	cin >> n;
	
	int* dp = new int[n];


	for (int i = 0; i < n; i++)
	{
		cin >> val;
		v.push_back(val);

	}

	dp[0] = v[0];
	dp[1] = v[0]+v[1];
	dp[2] = max(v[0] + v[2], v[1] + v[2]);
	
	if (n <= 3) // 0과 1일 때
	{
		cout << dp[n-1];
	}

	else
	{

		for (int i = 3; i <n; i++)
		{
			dp[i] = max(dp[i - 3] + v[i] + v[i - 1], dp[i - 2] + v[i]);
		}

		cout << dp[n - 1];
	}



	delete[] dp;
	return 0;
}