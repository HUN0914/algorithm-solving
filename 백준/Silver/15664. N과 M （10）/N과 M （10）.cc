#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m, arr[8], res[8]; //arr : 입력받은 수열, res : 길이m인 수열(출력)
bool chk[8] = { false }; //중복확인

void func(int cnt) {

	int count = 0;
	if (cnt == m) {

		for (int i = 0; i < m - 1; i++)
		{
			if (res[i] <=res[i + 1])
			{
				count++;
			}
		}

		if (count == m - 1)
		{

			for (int i = 0; i < m; i++)
				printf("%d ", res[i]);
			printf("\n");
		}
		return;
	}
	int xx = 0;
	for (int i = 0; i < n; i++) {
		if (!chk[i] && arr[i] != xx) {
			res[cnt] = arr[i];
			xx = res[cnt];
			chk[i] = true;
			func(cnt + 1);
			chk[i] = false;

			/*
			굳이 pushback, popback을 하는게 아니라 구조를 이해해야 한다.
			cnt는 dfs('0')을 주었기 때문에 재귀 때문에 +1, +1 ... 되는 구조이지
			본질 자체는 계속 0이다. 즉 재귀가 끝나면 0으로 돌아온 다는 것을 의미한다.
			그렇기에, chk함수를 통해 방문여부를 확인하고 (이건 늘 해오던것)
			방문하지 않았으면서, arr[i]과 직전 값과 다를떄에만 수행한다.
			그리고 1 3 5 9에서 9 9 가 나오는 것이 가능한 것은
			그 전까지의 값이 9 5 였기에, i=n-1일 때 xx의 값은 5이기에 담을수 있는 것이다.
			*/
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	func(0);
}