#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;
queue<int>q;
bool visited[100001];
vector<int>graph[100001];
int chk[100001];


void bfs(int cnt)
{
	int node = 1;
	q.push(cnt);
	visited[cnt] = true;
	chk[cnt] = node;

	while (!q.empty()) {

		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++)
		{
			/*
			방문 기록은 pop을 하면서 넣어주는게 아니라
			push로 들어갈 때마다 넣어주는 것이다.

			*/
			int y = graph[x][i];
			if (!visited[y])
			{
				node++;
				chk[y] = node;
				q.push(y);
				visited[y] = true;
			}
		}


	}


}

int main(void)
{
	cin >> n >> m >> k;
	int val1, val2;

	for (int i = 0; i < m; i++)
	{
		cin >> val1 >> val2;
		graph[val1].push_back(val2);
		graph[val2].push_back(val1);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	bfs(k);

	for (int i = 1; i <= n; i++)
	{
		cout << chk[i] << "\n";
	}

	return 0;
}