#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int node) {
	check[node] = true;
	for (int i = 0; i < 1; i++) { //일부로 1로 둠.
		int next = a[node][i];
		if (!check[next]) {
			dfs(next);
		}
	}
}

/*
	1	2	3	4	5	6	7	8 이라는 node가 선행으로 존재한다는 가정이다.

	그렇기에, 처음 어떤 수가 들어왔을 때, 그 위치의 수를 true로 놓고
	그 위치에서 a[node].siaze(여기서 항상 1이겠지)
	만큼 탐색을 해준다.
	그리고 그 과정에서 next=a[node][i]의 값을 넣어주는데,
	만약 초기 값이 3이라 하면
	1->3의 과정이 이루어졌고, 1~8까지의 값은 항상 존재하는 것이기에[기존 문제에서 주어진 default 값]
	3번째의 위치에 주어진 값
	(예제처럼 주어졌으면, 3	2	7	8	...) 이기에 7이 3번째의 위치의 값이 되겠다.
	그렇게, 싸이클을 돌리다가, 만약 if(check[next]==true) 
	즉, 값이 다 돌았으면 (하나의 순열 싸이클) 반복문을 실행하는데, 이전에 말했듯이
	node.size가 1이기에 종료가 되어 값을 reurn 한다.
	그리고 이 상황이 되었을 때, cnt++를 해주는 구조이다.
	만약, 이 문제가 한 번에 여러 node로 뻗을 수 있는 구조였다면,
	한 점에서의 탐색이 끝난 후, 그 점에서 인접한 점(처음 statrt한 점에 붙어있는 값)
	에서 다시 탐색을 시작할 것이다.




*/


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {		// 사용한 공간 초기화
			a[i].clear();
			check[i] = false;
		}
		for (int i = 1; i <= n; i++) {		// 방향 그래프 입력
			int v;
			cin >> v;
			a[i].push_back(v);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {		// 각 탐색마다 count + 1
			if (!check[i]) {
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}