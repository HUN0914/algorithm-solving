#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
vector<int>v;
vector<int>df;
bool sel[10001] = { 0, };

void dfs(int cnt)
{
	int count = 0;
	if (cnt == m)
	{
		for (int i = 0; i < m-1; i++)
		{
			if (df[i] < df[i + 1])
			{
				count++;
			}
		}

		if (count == m - 1)
		{
			for (int i = 0; i < m; i++)
			{
				cout << df[i] << " ";
			}
			cout << "\n";
		}
		return;

	}

	for (int j = 0; j < n; j++)
	{
		if (sel[j] == true)
		{
			continue;
		}
		sel[j] = true;
		df.push_back(v[j]);
		dfs(cnt + 1);
		sel[j] = false;
		df.pop_back();
	}

}


int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	int val;

	for (int i = 0; i < n; i++)
	{
		cin >> val;
		v.push_back(val);
	}

	sort(v.begin(), v.end());

	dfs(0);


	return 0;
}