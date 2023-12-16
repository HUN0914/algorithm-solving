#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int m, n;
int nx[4] = { 0,0,1,-1 };
int ny[4] = {1,-1,0,0 };
int visited[1001][1001] = { 0, };
int map[1001][1001] = { 0, };
int one_count = 0;
int day = 0;
queue<pair<int, int>>q;
bool inside(int ny, int nx)
{
	if (nx >=0 && ny >= 0 && nx < m && ny < n)
	{
		return true;
	}
	return false;
}

//어쨌든 q가 비어있을 경우에는 같다.

void bfs()
{
	while (!q.empty())
	{
		int dx = q.front().second;
		int dy = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int cx = dx + nx[i];
			int cy = dy + ny[i];

			if (inside(cy, cx) == true && map[cy][cx] == 0)
			{
				//map[cy][cx]==0일때만 이 조건이 되는 것이므로,
				//굳이 맵에 -1 조건이 있을 때 고려 안해도 O. 알아서 피해감(0일때만 추가하므로)
				map[cy][cx] = map[dy][dx] + 1;
				q.push({ cy,cx });
			}
		}
	}

}

int main(void)
{

	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				q.push({ i, j });
			}
		}
	}

	bfs();


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				cout << -1;
				return 0;
			}

			if (day < map[i][j])
			{
				day = map[i][j];
			}
		}
	}

	cout << day-1;

	return 0;
}