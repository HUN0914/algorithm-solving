#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool visited[1001];
int n, m;

void dfs(int cnt)
{
	visited[cnt] = true;

	for (int i = 0; i < graph[cnt].size(); i++)
	{
		int y = graph[cnt][i];
		if (!visited[y])
		{
			dfs(y);
		}
	}
}

int main(void)
{
	cin >> n >> m;
	int ans = 0;
	int val1, val2;

	for (int i = 0; i < m; i++)
	{
		cin >> val1 >> val2;
		graph[val1].push_back(val2);
		graph[val2].push_back(val1);

	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			dfs(i);
			ans++;
		}
	}

	cout << ans;

	return 0;
}