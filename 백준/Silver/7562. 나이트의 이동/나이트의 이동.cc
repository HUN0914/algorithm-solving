#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int nx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int ny[8] = { 2,1,-1,-2,2,1,-1,-2 };
int space;
int graph[301][301];
// 예시의 0,0 처음 위치, 7,0은 이동하고자 하는 위치

int last_x;
int last_y;

void bfs(int qx, int qy)
{
	for (int i = 0; i < 301; i++)
	{
		for (int j = 0; j < 301; j++)
		{
			graph[i][j] = 0;
		}

	}

	queue<pair<int, int>>q;
	q.push({ qx,qy });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();


		if (x == last_x && y == last_y)
		{
			cout << graph[x][y] << "\n";
			break;
			/*

			항상 움직이는 가정을 하고 최단거리를 구하는 것이기 때문에, 같을 경우는 미리
			예외 case로 분리해준다.

			*/
		}

		for (int i = 0; i < 8; i++)
		{
			int wx = x + nx[i];
			int wy = y + ny[i];

			if (wx < 0 || wx >= space || wy < 0 || wy >= space)
			{
				continue;
			}

			if (0 <= wx && 0 <= wy && wx < space && wy < space && !graph[wx][wy])
			{
				q.push({ wx,wy });
				graph[wx][wy] = graph[x][y] + 1;

			}

		}


	}



}

int main(void)
{
	int t;


	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> space;

		int val1, val2;

		cin >> val1 >> val2;

		cin >> last_x >> last_y;

		bfs(val1, val2);



	}


	return 0;
}
