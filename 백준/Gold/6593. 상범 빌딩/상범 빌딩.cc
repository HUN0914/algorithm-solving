#include <iostream>
#include  <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dz[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dx[6] = { 0,0,0,0,1,-1 };
int l, r, c;
char map[31][31][31];
int dist[31][31][31];
bool visited[31][31][31];
bool checking;

int maxing = 0;

struct space {
	int z;
	int y;
	int x;

};

queue<space>q;

void bfs()
{
	while (!q.empty())
	{
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx < 0 || nx >= c || ny < 0 || ny >= r || nz < 0 || nz >= l) continue;
			if (visited[nz][ny][nx]==true||map[nz][ny][nx]=='#') continue;

			if (map[nz][ny][nx] == 'E')
			{
				checking = true;
			}

			q.push({ nz,ny,nx });
			visited[nz][ny][nx] = true;
			dist[nz][ny][nx] = dist[z][y][x] + 1;


		}

	}

}


int main(void)
{

	while (1)
	{
		int aax = 0;
		int aay = 0;
		int aaz = 0;
		cin >> l >> r >> c;

		if (l == 0 && r == 0 && c == 0)
		{
			break;
		}

			for (int a = 0; a < l; a++)
			{
				for (int b = 0; b < r; b++)
				{
					for (int j = 0; j < c; j++)
					{
						cin >> map[a][b][j];

						if (map[a][b][j] == 'S')
						{
							visited[a][b][j] = true;
							q.push({ a,b,j });
						}

						if (map[a][b][j] == 'E')
						{
							aaz = a;
							aay = b;
							aax = j;
						}

					}
				}
			}

		checking = false;
		bfs();

		if (checking == false)
		{
			cout << "Trapped!" << "\n";
		}
		else
		{
			maxing = dist[aaz][aay][aax];

			cout << "Escaped in " << maxing << " minute(s)." << "\n";

		}

		for (int a = 0; a < 31; a++)
		{
			for (int b = 0; b < 31; b++)
			{
				for (int c = 0; c < 31; c++)
				{
					map[a][b][c]=NULL;
					dist[a][b][c]=0;
					visited[a][b][c]=false;

				}
			}
		}
		while (!q.empty())
		{
			q.pop();
		}

		maxing = 0;
	}

	return 0;

}