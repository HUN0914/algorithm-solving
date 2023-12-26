#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;

int qx[4] = { -1,1,0,0 };
int qy[4] = { 0,0,-1,1 };
char map[601][601];
bool visited[601][601];
queue<pair<int, int>>q;

int counti = 0;

int bfs(int cy, int cx)
{
	//int count = 0;

	q.push({ cy,cx });
	visited[cy][cx] = true;


	while (!q.empty())
	{
		int ny = q.front().first;
		int nx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{

			int wy = ny + qy[i];
			int wx = nx + qx[i];

			if (visited[wy][wx] == false && wy >= 0 && wx >= 0 && wy < n && wx < m)
			{
				visited[wy][wx] = true;

				if (map[wy][wx] == 'P')
				{
					counti++;
				}

				q.push({ wy,wx });
			}
		}
	}
	return counti;
}

int main(void)
{
	char val;
	int space_x = 0;
	int space_y = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'X')
			{
				visited[i][j] = true;
			}

			if (map[i][j] == 'I')
			{
				space_x = j;
				space_y = i;
			}

		}
	}

	if (bfs(space_y, space_x) == 0)
	{
		cout << "TT";
	}
	else
	{
		cout << bfs(space_y, space_x);
	}




	return 0;
}