// GitHub 참고

#include <bits/stdc++.h>

using namespace std;

int n, s;
int number[21];
int cnt = 0;

void check()
{
	for (int i = 0; i < n; i++)
		cin >> number[i];

}

void solve(int idx, int result)
{
	if (idx == n)
	{
		return;
	}
	if (number[idx] + result == s) cnt++;
	
	solve(idx + 1, result);

	solve(idx + 1, result + number[idx]);

}

int main(void)
{
	cin >> n >> s;
	check();
	solve(0, 0);
	cout << cnt;

	return 0;
}

