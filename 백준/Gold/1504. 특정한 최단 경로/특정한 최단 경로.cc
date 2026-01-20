#include <iostream>
#include <queue>
#define COST first
#define NODE second

using namespace std;

const long long INF=1e18;

long long d[200005];
vector<pair<int,int>> adj[200005];

int n,e;

void init() {
    for (int i=0; i<=n; i++) {
        d[i]=INF;
    }
}

void fastRoot(int s) {
    priority_queue<pair<long long ,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    init();
    d[s]=0;
    pq.push({d[s],s});

    while (!pq.empty()) {
        auto cur= pq.top();
        pq.pop();

        long long currCost=cur.COST;
        int currNode=cur.NODE;

        if (d[currNode]!=currCost) continue;

        for (auto nxt : adj[currNode]) {
            long long nxtCost=nxt.COST;
            int nxtNode=nxt.NODE;
            if (d[nxtNode]<=nxtCost+currCost) continue;

            d[nxtNode]=nxtCost+currCost;
            pq.push({d[nxtNode],nxtNode});
        }
    }
}

long long goFirstOne(int onePoint, int twoPoint) {
    long long compareOne=0;
    fastRoot((1));
    compareOne+=d[onePoint];
    fastRoot(onePoint);
    compareOne+=d[twoPoint];
    fastRoot(twoPoint);
    compareOne+=d[n];

    return compareOne;
}

long long goFirstTwo(int onePoint, int twoPoint) {
    long long compareTwo=0;
    fastRoot((1));
    compareTwo+=d[twoPoint];
    fastRoot(twoPoint);
    compareTwo+=d[onePoint];
    fastRoot(onePoint);
    compareTwo+=d[n];

    return compareTwo;
}

void game(int onePoint, int twoPoint) {
    long long val1=goFirstOne(onePoint,twoPoint);
    long long val2=goFirstTwo(onePoint,twoPoint);

    if (min(val1,val2)>=INF) cout<<"-1";
    else cout<<min(val1,val2);
}

void input() {
    cin>>n>>e;
    for (int i=0; i<e; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    int onePoint, twoPoint;
    cin>>onePoint>>twoPoint;

    game(onePoint,twoPoint);
}

int main() {
    input();
}