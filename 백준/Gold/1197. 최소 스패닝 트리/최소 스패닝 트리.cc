#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int find(int x, vector<int>& p) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x], p);
}

bool is_diff_group(int u, int v, vector<int>& p) {
    u = find(u, p);
    v = find(v, p);
    if (u == v) return false;
    if (p[u] == p[v]) p[u]++;
    if (p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e;
    cin >> v >> e;

    vector<int> p(v + 1, -1); // 벡터의 크기를 v+1로 변경하고, 초기값을 -1로 설정합니다.

    tuple<int, int, int> edge[100005];
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = { cost, a, b };
    }
    sort(edge, edge + e);
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if (!is_diff_group(a, b, p)) continue;
        ans += cost;
        cnt++;
        if (cnt == v - 1) break;
    }
    cout << ans;
    return 0;
}
