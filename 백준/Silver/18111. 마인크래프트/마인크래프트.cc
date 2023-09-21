#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int board[502][502];

void solve() {
	int n, m, b;
	int mintime = 1e9;
	int maxheight = -1;

	cin >> n >> m >> b;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int height = 0; height <= 256; height++)
	{
		int inven = 0;//인벤에서 꺼내는게 필요한거1초 늘어남
		int remove = 0;//제거하는 양 2초 늘어남 개수

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int cut = board[i][j] - height;
				if (cut < 0) //보관함에서 꺼낸 횟수가 더 많은 경우
				{
					inven -= cut;
				}
				else //보관함에서 꺼낸 횟수보다 제거해서 인벤에 넣어야 하는 수가 많은 경우
				{
					remove += cut;
				}
			}
		}
		if (remove + b >= inven) {
			int ttime = inven + 2 * remove;

			if (mintime >= ttime)
			{
				mintime = ttime;
				//최소 시간을 구하는 것

				maxheight = height;
			}
		}

	}

	cout << mintime << " " << maxheight;

}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();

	return 0;
}