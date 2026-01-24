#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define NODE second
#define COST first

using namespace std;

int n,m,x;

int d[1001];
vector<pair<int,int>> adj[10001];
vector<int>students;

void init() {
    for (int i=0; i<=n; i++) {
        d[i]=1e9;
    }
}

void input() {
    cin>>n>>m>>x;

    for (int i=0; i<m; i++) {
        int u,v,t;
        cin>>u>>v>>t;
        adj[u].push_back({t,v});
    }
}

void dijkstra(int s) {
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;

    init();
    d[s]=0;
    pq.push({d[s],s});

    while (!pq.empty()) {
        int curCost = pq.top().COST;
        int curNode = pq.top().NODE;
        pq.pop();

        if (d[curNode]!=curCost) continue;

        for (auto & next : adj[curNode]) {
            int nextCost = next.COST;
            int nextNode = next.NODE;
            if (d[nextNode]> curCost+nextCost) {
                d[nextNode]= curCost+nextCost;
                pq.push({d[nextNode], nextNode});
            }

        }
    }
}

void total() {

    students.resize(n+1);

    for (int i=1; i<=n; i++) {
        dijkstra(i);
        students[i]+=d[x];
        dijkstra(x);
        students[i]+=d[i];
    }

    sort(students.begin(), students.end());
    cout<<students[n];
}

void game() {
    input();
    total();
}

int main() {
    game();

    return 0;
}