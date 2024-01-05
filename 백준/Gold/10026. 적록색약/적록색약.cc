#include <iostream>
#include <queue>

using namespace std;

int qx[4] = {1,-1,0,0 };
int qy[4] = { 0,0,1,-1 };

char greed[101][101];
bool visited[101][101];
queue<pair<int, int>>q;

int red_count = 0;
int blue_count = 0;
int green_count = 0;

int n;

void clear()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = false;
		}
	}
}

void setting()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (greed[i][j] == 'G')
			{
				greed[i][j] = 'R';
			}
		}
	}

}

void red_bfs()
{
	while (!q.empty())
	{
		int ny = q.front().first;
		int nx = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dy = ny + qy[i];
			int dx = nx + qx[i];

			if (dy < 0 || dy >= n || dx < 0 || dx >= n) continue;

			if (visited[dy][dx] == false && greed[dy][dx] == 'R')
			{
				visited[dy][dx] = true;
				q.push({ dy,dx });
			}


		}

		
	}

}

void blue_bfs()
{
	while (!q.empty())
	{
		int ny = q.front().first;
		int nx = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dy = ny + qy[i];
			int dx = nx + qx[i];

			if (dy < 0 || dy >= n || dx < 0 || dx >= n) continue;

			if (visited[dy][dx] == false && greed[dy][dx] == 'B')
			{
				visited[dy][dx] = true;
				q.push({ dy,dx });
			}


		}


	}

}

void green_bfs()
{
	while (!q.empty())
	{
		int ny = q.front().first;
		int nx = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dy = ny + qy[i];
			int dx = nx + qx[i];

			if (dy < 0 || dy >= n || dx < 0 || dx >= n) continue;

			if (visited[dy][dx] == false && greed[dy][dx] == 'G')
			{
				visited[dy][dx] = true;
				q.push({ dy,dx });
			}


		}


	}

}

int main(void)
{
	int first;
	int second;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> greed[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (greed[i][j] == 'R'&&visited[i][j]==false)
			{
				visited[i][j] = true;
				q.push({ i,j });
				red_bfs();
				red_count++;
			}

			if (greed[i][j] == 'B'&&visited[i][j] == false)
			{
				visited[i][j] = true;
				q.push({ i,j });
				blue_bfs();
				blue_count++;

			}

			if (greed[i][j] == 'G'&& visited[i][j] == false)
			{
				visited[i][j] = true;
				q.push({ i,j });
				green_bfs();
				green_count++;
			}
		}
	}
	first= red_count + blue_count + green_count;

	red_count = 0;
	blue_count = 0;

	clear();
	setting();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (greed[i][j] == 'R' && visited[i][j] == false)
			{
				visited[i][j] = true;
				q.push({ i,j });
				red_bfs();
				red_count++;
			}

			if (greed[i][j] == 'B' && visited[i][j] == false)
			{
				visited[i][j] = true;
				q.push({ i,j });
				blue_bfs();
				blue_count++;

			}
		}
	}

	second = red_count + blue_count;

	cout << first << " " << second;

	return 0;
}