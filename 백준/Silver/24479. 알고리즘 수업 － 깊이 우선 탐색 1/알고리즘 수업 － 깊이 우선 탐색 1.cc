#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using namespace std;

int N, M, R;
vector<int> connect[100001];
int check[100001];
int Cnt[100001];
int cnt = 1;

void dfs(int node) {
    check[node] = 1;
    Cnt[node] = cnt++;
    /*
    방문된 수가 아니라 순서임을 인지하자. 그렇기에
    cnt[node]=cnt++를 저장하는 것이다.

    */
    for (int i = 0; i < connect[node].size(); i++) {
        int x = connect[node][i];
        if (check[x] == 0) {
            dfs(x);
        }
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        sort(connect[i].begin(), connect[i].end());
    }
    dfs(R);
    for (int i = 1; i <= N; i++) {
        cout << Cnt[i] << "\n";
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> R;
    for (int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;
        connect[x].push_back(y);
        connect[y].push_back(x);
    }
    solve();
    return 0;
}