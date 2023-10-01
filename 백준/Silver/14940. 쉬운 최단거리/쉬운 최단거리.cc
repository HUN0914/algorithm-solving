#include <iostream>
#include <queue>


using namespace std;


int map[1001][1001];
bool visit[1001][1001];


int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue<pair<int, int>>q;

int n, m;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{ /*
		  1,-1,0,1을 구분 없이 상하좌우 움직이도록만 설정해주면 되는 이유
		  어짜피, 어떠한 정점으로 상하좌우는 +1의 거리가 존재한다. 그렇기에,
		  모두 1을 더해주고 각각의 점에서 한칸씩 멀어지는 경우에도 다 +1을 해주는 것이고, 이렇게만
		  구현을 함과 동시에 방문된 곳은 다시 안 간다는 조건을 걸어주면 어떠한 경우에도
		  최단 거리만 값에 저장되게 된다.
		  */
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (visit[nx][ny] == false)
				{
					map[nx][ny] = map[x][y] + 1; //그 점에서 상하좌우는 거리가 모두 1이기에 +1을 해주는 것
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}


int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				map[i][j] = 0;
				q.push({ i,j });
				visit[i][j] = true;
			}
			else if (map[i][j] == 0)
			{
				visit[i][j] = true;
			}
		}
	}

	bfs();

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (visit[x][y] == false)
			{
				cout << -1<<" ";
			}
			else
			{
				cout << map[x][y]<<" ";
			}
		}
		cout << "\n";
	}
	return 0;
}