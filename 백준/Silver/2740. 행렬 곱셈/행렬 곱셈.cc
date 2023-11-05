#include <iostream>


using namespace std;

int pro1[101][101];
int pro2[101][101];
int res[101][101];

int main()
{
	int N, M, K;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pro1[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> pro2[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {
				res[i][j] += pro1[i][k] * pro2[k][j];
			}
			/*
			
			한 행의 연산이 끝날 때까지 처음 행렬의 행 값은 바뀌지 않는다는 걸
			알아내고, 한 행에서 한 칸의 연산이 끝날 때마다 나중 행렬의 열 값은 N*M 행렬에서
			M크기 만큼 증가한다는 것만 알면 된다.
			*/
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}