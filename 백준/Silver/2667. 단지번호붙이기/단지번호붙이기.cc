#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

int nx[4] = { 1,-1,0,0 };
int ny[4] = { 0,0,1,-1 };
bool visited[26][26];
int space[26][26];
int n;
vector<int>chk;
queue<pair<int, int>>q;

void bfs(int y1, int x1)
{
	int value = 1;

	q.push({ y1,x1 });
	visited[y1][x1] = true;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int j = 0; j < 4; j++)
		{
			int dx = x + nx[j];
			int dy = y + ny[j];

			if (dx >= 0 && dx < n && dy >= 0 && dy < n)
			{
				if (!visited[dy][dx])
				{
					visited[dy][dx] = true;
					q.push({ dy,dx });
					value++;
				}
			}
		}
	}

	chk.push_back(value);

}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &space[i][j]);

			if (space[i][j] == 0)
			{
				visited[i][j] = true;
			}
			
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				bfs(i, j);
			}
		}
	}

	sort(chk.begin(), chk.end());

	std::cout << chk.size() << "\n";
	for (int i = 0; i < chk.size(); i++)
	{
		std::cout << chk[i] << "\n";
	}


	return 0;
}