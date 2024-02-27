#include <bits/stdc++.h>

using namespace std;

int mapp[51][51];
bool visited[51][51];
int counting;
queue<pair<int,int>>q;


int nx[8] = { -1,-1,-1,1,1,1,0,0 };
int ny[8] = { -1,1,0,-1,1,0,1,-1};

int w, h;

void bfs(int py, int px)
{
	counting++;

	q.push({py,px});
	visited[py][px] = true;

	while (!q.empty())
	{
		int dy = q.front().first;
		int dx = q.front().second;

		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int qy = dy + ny[i];
			int qx = dx + nx[i];

			if (qy > h || qy<1 || qx>w || qx < 1) continue;

			if (!visited[qy][qx]&&mapp[qy][qx]==1)
			{
				//counting++;
				q.push({ qy,qx });
				visited[qy][qx] = true;

			}			
		}


	}

}

void clear()
{
	for (int i = 1; i <= 50; i++)
	{
		for (int j = 1; j <= 50; j++)
		{
			visited[i][j] = false;
		}
	}

}


int main(void)
{
	while (1)
	{
		clear();

		counting = 0;

		cin >> w >> h;

		if (w == 0 && h == 0)
		{
			break;
		}

		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
				cin >> mapp[i][j];
		}

		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				if (mapp[i][j] == 1&&!visited[i][j])
				{
					bfs(i, j);
				}
			}
		
		}
		cout << counting<<"\n";

	}

	return 0;
}