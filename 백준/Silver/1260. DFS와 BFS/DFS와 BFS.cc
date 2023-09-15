#include <iostream>
#include <queue>
#include <vector> 
#include <algorithm>
using namespace std;

int number = 9;
bool visit[1001];
vector<int> a[1001];
vector<int> b[1001];

void bfs(int start) {
    queue<int> q;
    q.push(start);

    visit[start] = true;

    while (!q.empty()) {
        // 큐에 값이 있을경우 계속 반복 실행
        // 큐에 값이 있다. => 아직 방문하지 않은 노드가 존재 한다. 
        int x = q.front();
        q.pop();
        printf("%d ", x);
      
        //sort(a[x].begin(), a[x].end()); ---> 뻗어있는 가지들을 정렬한다고 생각하면 됨.

        for (int y : a[x]) {
            if (!visit[y]) {
                // 방문하지 않았다면..
                q.push(y);
                visit[y] = true;
            }
        }

    }
}

void dfs(int cnt) {

    visit[cnt] = true;
    cout << cnt << " ";
    sort(a[cnt].begin(), a[cnt].end());
    for (int y : a[cnt]) // 인접한 노드 사이즈만큼 탐색
    {
        // int y = a[cnt][i];
        if (!visit[y]) // 방문하지 않았으면 즉 visited가 False일 때 not을 해주면 True가 되므로 아래 dfs 실행
            dfs(y); // 재귀적으로 방문
    }
}


int main(void) {

    int n, m, t;

    int one;
    int two;

   cin >> n >> m >> t;

    for (int i = 0; i < m; i++)
    {
        cin >> one >> two;

        a[one].push_back(two);
        a[two].push_back(one);


    }

    dfs(t);
    cout << "\n";
    for (int i = 0; i < 1001; i++)
    {
        visit[i] = false;
    }
   bfs(t);

    return 0;
}