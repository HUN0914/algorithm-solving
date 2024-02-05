#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <deque>

using namespace std;

long long dp[1025][1025];

int n;
int m;

void dpp(int y1, int x1, int y2, int x2)
{
	int result = 0;

	for (int i = y1; i <= y2; i++)
	{
		result += dp[i][x2] - dp[i][x1-1];
	}

	cout << result;

}

int main(void)
{
	int x1;
	int y1;
	int x2;
	int y2;

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	int val;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> val;
			dp[i][j] += dp[i][j-1] + val;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> y1 >> x1 >> y2 >> x2;
		dpp(y1, x1, y2, x2);
		cout << "\n";

	}

	return 0;
}