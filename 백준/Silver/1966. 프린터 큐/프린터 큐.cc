#include <queue>
#include <iostream>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n,m;
		cin >> n >> m;

		int cnt = 0;

		queue<pair<int, int>> q;
		priority_queue<int> pq; // 기본적으로 최대 힙 


		for (int j = 0; j < n; j++)
		{
			int x;

			cin >> x;

			q.push({ j,x });
			pq.push(x);
		}

		while (!q.empty())
		{
			int idx = q.front().first;
			int priority = q.front().second;
			q.pop(); //q의 위치, 값을 idx, prioirty에 저장 후 값 제거
			
			if (pq.top() == priority)
			{
				pq.pop();
				cnt++; //문서를 인쇄할 때마다 증가

				if (idx == m) {
					cout << cnt << '\n';
					break;
				}
			}
			else
			{
				q.push({ idx, priority });
				//pop한 값을 다시 추가 (탑 값이 아닐 경우[제일 큰 값이 아닌 경우] 마지막으로 넘김
			}

		}

	}

	return 0;

}

