#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maping[8][8];
vector<pair<int, int>>v;
int n, m;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
int mini = 987654321;

void initial() {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> maping[i][j];
			
			if (maping[i][j] != 0 && maping[i][j] != 6)
			{
				v.push_back({ i,j });
			}
		}
	}

}

void check(int y, int x, int dir)
{
	dir %= 4;

	while (1) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		x = nx;
		y = ny;
		/*
		
		!! 반복문이다 !!
		x=nx, y=ny로 갱신 안해주면 무한 루프에 빠질 수도 있음.
		우리의 목적은 ***각 위치****에서 어떤 카메라이냐에 따라서
		하나하나씩 위치를 봐주는 것이기 때문에 위와 같이 해줘야 한다.
		
		*/

		if (nx < 0 || nx >= m || ny < 0 || ny >= n) return;
		if (maping[ny][nx] == 6) return;
		if (maping[ny][nx] != 0) continue;
		maping[ny][nx] = -1;
		
	}

}

void dfs(int cnt)
{
	if (cnt == v.size())
	{
		int result = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!maping[i][j]) result++;
			}
		}
		mini = min(mini, result);
		return;
	}

	int x = v[cnt].first;
	int y = v[cnt].second;
	int tmp[9][9];

	for (int dir = 0; dir < 4; dir++) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				tmp[i][j] = maping[i][j]; 
		/*
		여러 케이스를 봐야하므로, 
		각 초기 배열값을 재귀 시작전에 늘 갖고 감. 즉, 재귀로 돌아올 때마다의
		그떄 사용한 case는 없던 취급을 해줘야 하기 때문에, 반복문 안에서 담아준 것이다.
		*/
		
		//여기서 하는 dir은 dx,dy 배열에 담긴 값에 따른 위치 구분
		if (maping[x][y] == 1)
		{
			check(x, y, dir);
		}
		else if (maping[x][y] == 2)
		{
			check(x, y, dir);
			check(x, y, dir + 2);
		}
		else if (maping[x][y] == 3)
		{
			check(x, y, dir);
			check(x, y, dir + 1);
		}
		else if (maping[x][y] == 4) {
			check(x, y, dir);
			check(x, y, dir + 1);
			check(x, y, dir + 2);
		}
		else if (maping[x][y] == 5) {
			check(x, y, dir);
			check(x, y, dir + 1);
			check(x, y, dir + 2);
			check(x, y, dir + 3);
		}

		dfs(cnt + 1);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				maping[i][j] = tmp[i][j];
		/*
		손상된 배열을 돌려주는 것.
		*/
	}

}

int main(void)
{
	cin >> n >> m;
	
	initial();
	dfs(0);

	cout << mini << '\n';

	return 0;
}