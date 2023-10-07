#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> graph[100001];
int chk[100001];
int node = 1;
bool visited[100001];


void dfs(int cnt)
{
	queue<int>q;
	q.push(cnt);
	visited[cnt] = true;
	chk[cnt] = node;

	while(!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			if (!visited[y])
			{
				node++;
				chk[y] = node;
				visited[y] = true;
				q.push(y);

			}
		}

	}


}

int main(void)
{
	int n, m, k;
	int val1, val2;
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		cin >> val1 >> val2;
		graph[val1].push_back(val2);
		graph[val2].push_back(val1);

	}

	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end(), greater<>());
	}
	dfs(k);

	for (int i = 1; i <= n; i++)
	{
		cout << chk[i] << "\n";
	}



	return 0;
}