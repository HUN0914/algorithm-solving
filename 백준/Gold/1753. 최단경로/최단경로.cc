#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define COST first
#define NODE second

const int INF = 1e9;

int v,e,s;
int d[20005];

vector<pair<int,int>> adj[20005];

int main() {

    cin>>v>>e>>s;

    fill(d,d+v+1,INF);

    for (int i=0; i<e; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    d[s]=0;
    pq.push({d[s],s});

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        int currCost= cur.COST;
        int currNode=cur.NODE;
        if (d[currNode]!=currCost) continue;

        for (auto nxt : adj[currNode]) {
            int nextCost=nxt.COST;
            int nextNode=nxt.NODE;

            if (d[nextNode]<=currCost+nextCost) continue;

            d[nextNode]=currCost+nextCost;
            pq.push({d[nextNode],nextNode});
        }
    }

    for (int i=1; i<=v; i++) {
        if (d[i]==INF) cout<<"INF"<<"\n";
        else cout<<d[i]<<"\n";
    }

}