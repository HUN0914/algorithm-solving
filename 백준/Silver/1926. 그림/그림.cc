#include <bits/stdc++.h>

using namespace std;

bool visited[501][501];
int maping[501][501];
int n, m;
int maxing;
int cnt;
int map_cnt;

queue<pair<int,int>>q;

int nx[4] = { -1,1,0,0 };
int ny[4] = { 0,0,-1,1 };

void solve(int py, int px)
{
	cnt = 0;
	q.push({ py,px });
	visited[py][px] = true;

	while (!q.empty())
	{
		int dy = q.front().first;
		int dx = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ay = dy + ny[i];
			int ax = dx + nx[i];

			if (ay < 0 || ay >= n || ax < 0 || ax >= m||visited[ay][ax]) continue;

			if (maping[ay][ax] == 1)
			{
				visited[ay][ax] = true;
				q.push({ ay,ax });
			}
		}
		cnt++;

	}

	if (maxing < cnt) maxing = cnt;

	return;
}

void map_count() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> maping[i][j];
		}
	}
}

int main(void)
{
	cin >> n >> m;
	map_count();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maping[i][j] == 1 && !visited[i][j])
			{
				map_cnt++;
				solve(i, j);
			}
		}
	}
	
	cout << map_cnt<< "\n" << maxing;

	return 0;
}