#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int graph[100001];

void bfs(int cnt) {
    queue<int> q;
    q.push(cnt);

    while (!q.empty()) {
        int x = q.front();
        q.pop();



        for (int i = 0; i < 3; i++) {
            int next_x;

            if (i == 0) {
                next_x = x + 1;
            }
            else if (i == 1) {
                next_x = x - 1;
            }
            else {
                next_x = x * 2;
            }

            if (next_x >= 0 && next_x <= 100000 && !graph[next_x]) {
                q.push(next_x);
                graph[next_x] = graph[x] + 1;
            }
        }
    }
}

int main(void) {
    cin >> n >> k;

    if (n == k)
    {
        cout << 0;
    }
    else
    {
        bfs(n);


        cout << graph[k];  // 'k'에 도달하는 최소 단계 수를 출력
    }
    return 0;
}
