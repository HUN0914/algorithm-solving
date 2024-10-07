#include <bits/stdc++.h>

using namespace std;

int mapp[1001][1001][2];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int bfs(int n, int m) {
	queue<pair<int, pair<int, int>>> q;

	q.push({ 0 ,{ 0,0 } });

	while (!q.empty()) {

		int broken = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if(x==n-1&&y==m-1){
			return mapp[n - 1][m - 1][broken] + 1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}

			if (mapp[nx][ny][0] == 1) {

				if (!broken) {
					mapp[nx][ny][1] = mapp[x][y][broken] + 1;
					q.push({ 1,{nx,ny} });
				}

			}
			else if (mapp[nx][ny][0] == 0) {
				if (broken==1 &&mapp[nx][ny][broken]) {
					continue;
				}
				/*
				* mapp[nx][ny][broken]은 bfs 특성상 그리고 여기서 만들어준
				* 0,1(벽 부술 때 안 부술때 )나누어준 특성 상 저 값에 특정 값이
				* 존재한다면 최솟값이라는 것 의미
				*/
				mapp[nx][ny][broken] = mapp[x][y][broken] + 1;
				q.push({ broken, { nx, ny } });

			}
		}
	}

	return -1;
}


int main(void) {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			char tmp;
			cin >> tmp;
			mapp[i][j][0]= tmp-'0';
		}

	}


	cout << bfs(n, m);

	return 0;
}