#include <iostream>
#include <vector>
#include <queue>

#define COST first
#define NODE second
using namespace std;
int n,m;

vector<pair<int,int>> adj[1001];

void bfs(int start, int end) {

    bool isVisited[1001]={false};

    queue<pair<int,int>> q;
    q.push({0, start});
    isVisited[start]=true;

    while (!q.empty()) {
        auto cur= q.front();
        int curCost=cur.COST;
        int curNode=cur.NODE;
        q.pop();
        for (auto nxt : adj[curNode]) {

            int nextCost=nxt.COST;
            int nextNode=nxt.NODE;

            if (isVisited[nextNode]) continue;
            isVisited[nextNode]=true;

            if (nextNode==end) {
                cout<<nextCost+curCost<<"\n";
                return;
            }
            q.push({nextCost+curCost, nextNode});
        }
    }
}

void input() {
    cin>>n>>m;
    for (int i=0; i<n-1; i++) {
        int start,end, cost;
        cin>>start>>end>>cost;
        adj[start].push_back({cost,end});
        adj[end].push_back({cost,start});
    }

    for (int i=0; i<m; i++) {
        int one, two;
        cin>>one>>two;;
        bfs(one,two);
    }
}

int main() {
    input();

    return 0;
}