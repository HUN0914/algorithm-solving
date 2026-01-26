#include <iostream>
#include <queue>
#include <vector>

#define COST first
#define NODE second
#define INF 1e9

using namespace std;
long long d[101];
vector<pair<long long,int>> adj[100001];

int n,m;

void dijkstra(int s) {

    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    for (int i=1; i<=n; i++) {
        d[i]=INF;
    }

    d[s]=0;
    pq.push({d[s],s});

    while (!pq.empty()) {
        auto cur=pq.top();
        pq.pop();
        long long curCost=cur.COST;
        int curNode=cur.NODE;
        if (d[curNode]!=curCost) continue;

        for (auto & nxt : adj[curNode]) {
            long long nextCost=nxt.COST;
            int nextNode=nxt.NODE;

            if (d[nextNode]<=curCost+nextCost) continue;
            d[nextNode]=curCost+nextCost;
            pq.push({d[nextNode], nextNode});
        }
    }

}

void input() {
    cin>>n>>m;

    for (int i=0; i<m; i++) {
        int a,b;
        long long c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
    }

    for (int i=1; i<=n; i++) {
        dijkstra(i);
        for (int j=1; j<=n; j++) {
            if (d[j]>=INF) cout<<"0 ";
            else cout<<d[j]<<" ";
        }
        cout<<"\n";
    }

}

int main() {
    input();
}