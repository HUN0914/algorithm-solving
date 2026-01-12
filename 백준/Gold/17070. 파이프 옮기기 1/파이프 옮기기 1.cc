#include <iostream>

using namespace std;

int map[17][17];
int dy[3]={0,1,1};
int dx[3]={1,0,1};
int n;
int answer=0;

void dfs(int y, int x, int dir) {

    if (y==n-1&&x==n-1) {
        answer++;
        return;
    }

    for (int i=0; i<3; i++) {
        int ny=y+dy[i];
        int nx=x+dx[i];

        if (ny>=n||ny<0||nx>=n||nx<0) continue;
        if (map[ny][nx]==1) continue;
        if (i==0 && dir==1) continue;
        if (i==1 && dir==0) continue;
        if (i==2&& (map[y+1][x]==1||map[y][x+1]==1)) continue;
        dfs(ny,nx,i);

    }

}

int main() {

    cin>>n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>map[i][j];
        }
    }

    dfs(0,1,0);

    cout<<answer;

    return 0;
}