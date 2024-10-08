#include <bits/stdc++.h>

using namespace std;

int mapp[100001];
bool selected[100001];
/*
+ - 1 해준거랑 ,*2 해준거랑 q에 넣어주고 
위치에 대해서 +-은 시간 값이니까 시간값 추가

*/

int bfs(int first, int end ) {

	deque<int> q;
	q.push_back(first);
    selected[first] = true;
	
	while (!q.empty()) {

		int x = q.front();

		int plu = x + 1;
		int minus = x - 1;
		int mul = x * 2;

		q.pop_front();

        if (x == end) {
            return mapp[end];
        }

		if (mul < 100001 && !selected[mul]) {
			q.push_front(mul);
			selected[mul] = true;
			mapp[mul] = mapp[x];
		}
	
		if (minus >= 0 && !selected[minus]) {
			q.push_back(minus);
			selected[minus] = true;
			mapp[minus] = mapp[x] + 1;
		}

		if (plu < 100001 && !selected[plu]) {
			q.push_back(plu);
			selected[plu] = true;
			mapp[plu] = mapp[x] + 1; 
		}

		
	}
		return mapp[end];
}
	

int main(void) {

	int n, m;
	cin >> n >> m;

	cout << bfs(n, m);

	return 0;
}