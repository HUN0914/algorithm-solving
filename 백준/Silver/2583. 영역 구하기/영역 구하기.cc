#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<bool>> isVisited(101, vector<bool>(101));
vector<int> squareList;
int n,m,k;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

void bfs(int i, int j) {

    queue<pair<int,int>>q;
    q.push({i,j});
    isVisited[i][j]=true;
    int cnt=1;
    while (!q.empty()) {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int py=y+dy[k];
            int px=x+dx[k];
            if (py<0||py>=n||px<0||px>=m||isVisited[py][px]) continue;
            isVisited[py][px]=true;
            q.push({py,px});
            cnt++;
        }
    }
    squareList.push_back(cnt);
}

void game() {

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!isVisited[i][j]) bfs(i,j);
        }
    }
}

void input() {
    cin>>n>>m>>k;

    for (int i=0; i<k; i++) {
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        for (int j=y1; j<y2; j++) {
            for (int q=x1; q<x2; q++) {
                isVisited[j][q]=true;
            }
        }
    }
}

void output() {
    cout<<squareList.size()<<"\n";
    sort(squareList.begin(), squareList.end());
    for (auto & i : squareList) cout<<i<<" ";
    cout<<"\n";

}

int main() {
    input();
    game();
    output();

    return 0;
}