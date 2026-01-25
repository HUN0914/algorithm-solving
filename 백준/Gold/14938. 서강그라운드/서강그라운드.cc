#include <iostream>
#include <queue>>
#define COST first
#define NODE second

using namespace std;

int INF = 1e9;
int n,m,r;
int item[101];
int d[101];

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
vector<pair<int,int>> adj[101];

void dijkstra(int s) {
    for (int i=1; i<=n; i++) d[i]=INF;

    d[s]=0;
    pq.push({d[s],s});

    while (!pq.empty()) {
        auto cur=pq.top();
        int curNode=cur.NODE;
        int curCost=cur.COST;
        pq.pop();

        if (d[curNode]!=curCost) continue;

        for (auto & next : adj[curNode]) {
            int nextCost=next.COST;
            int nextNode=next.NODE;

            if (d[nextNode]<=nextCost+curCost) continue;
            d[nextNode]=nextCost+curCost;

            pq.push({d[nextNode], nextNode});
        }
    }
}

int cal() {
    int maximum=0;

    for (int i=1; i<=n; i++) {
        int total=0;
        dijkstra(i);
        for (int j=1; j<=n; j++) {
            if (d[j]<=m) total+=item[j];
        }
        maximum=max(total,maximum);
    }

    return maximum;
}

void input() {

    cin>>n>>m>>r;
    for (int i=1; i<=n; i++) cin>>item[i];
    for (int i=1; i<=r; i++) {
        int a,b,l;
        cin>>a>>b>>l;
        adj[a].push_back({l,b});
        adj[b].push_back({l,a});
    }
}

void game() {
    input();
    int result=cal();
    cout<<result;
}

int main() {
    game();

    return 0;
}