#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int let[6] = { 1,2,3,4,5,6 };
int map[103];

int n, m;
int x, y;
queue<int>q;
int visited[103];

void bfs()
{
	q.push(1);

	while (!q.empty())
	{
		int nx = q.front();
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int dx = nx + let[i];

			if (visited[dx]||visited[map[dx]]||dx>100) continue;

			if (map[dx] != 0)
			{
				dx = map[dx];
			}

			q.push(dx);
			visited[dx] = visited[nx] + 1;

		}
	}


}

int main(void)
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		map[x] = y;
	}
	
	for (int j = 0; j < m; j++)
	{
		cin >> x >> y;
		map[x] = y;
	}

	bfs();

	cout << visited[100];

	return 0;
}