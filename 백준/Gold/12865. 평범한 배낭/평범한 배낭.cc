#include <bits/stdc++.h>

using namespace std;

int obj[101][100001];
int weight[101];
int value[101];


int main(void) {

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
		cin >> value[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= weight[i]) {
				obj[i][j]= max(obj[i - 1][j], obj[i - 1][j - weight[i]] + value[i]);
			}
			else
			{
				obj[i][j] = obj[i - 1][j];
			}
		}
		//무게가 1일 때부터 maximum 무게일때까지 올라가고, 그때마다 배낭에 담을수 있는지 체크해줌
		//i=1부터 n까지란건 1번째 물건을 담을 때의 maximum case를 구하고 그 다음부터 2번째 ,,, n번째
		//무게를 담을 때까지 maxmimum case를 기억하면서 가는 구조
	}
	cout << obj[n][k];


	return 0;
}