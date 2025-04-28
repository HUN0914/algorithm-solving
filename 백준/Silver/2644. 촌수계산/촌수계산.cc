#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[101];
bool visited[101];

int bfs(int n, int m) {
    queue<pair<int,int>> q;
    q.push({n,0});
    visited[n]=true;

    while (!q.empty()) {
        int x=q.front().first;
        int dist=q.front().second;
        if (x==m) {
            return dist;
        }
        q.pop();

        for (int i=0; i<graph[x].size(); i++) {
            int y=graph[x][i];
            if (!visited[y]) {
                q.push({y,dist+1});
                visited[y]=true;
            }
        }
    }

    return -1;
}

int main() {

    int t;
    int father, son;
    int pair;

    cin>>t;
    cin>>father>>son;
    cin>>pair;

    for (int i=0; i<pair; i++) {
        int n,m;
        cin>>n>>m;
        graph[n].push_back(m);
        graph[m].push_back(n);
    }

    int answer= bfs(father, son);
    cout<<answer;

}