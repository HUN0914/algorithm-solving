#include <iostream>
#include <algorithm>

using namespace std;

int t;
int n;
int dp[2][100001];
int arr[2][100001];


void dpp(int some)
{

	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];

	dp[0][1] = arr[0][1] + dp[1][0];
	dp[1][1] = arr[1][1] + dp[0][0];
	//초기값 저장 개중요
	
	for (int i = 2; i < n; i++)
	{
		dp[0][i] = arr[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
		dp[1][i] = arr[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
	}

	cout << max(dp[1][some - 1], dp[0][some - 1])<<"\n";


}

int main(void)
{
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		
		for (int k = 0; k < n; k++)
		{
			cin >> arr[0][k];
		}
		for (int k = 0; k < n; k++)
		{
			cin >> arr[1][k];
		}


		
		
		dpp(n);
	
	}


}