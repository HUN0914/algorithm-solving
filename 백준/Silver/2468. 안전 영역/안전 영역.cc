#include <iostream>
#include <queue>

using namespace std;
int board[101][101];
int n;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

struct location {
    int y;
    int x;
};

int bfs(int board[101][101], int cnt) {

    bool isRain[101][101];
    bool isVisited[101][101];
    int value=0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            isRain[i][j]=false;
            isVisited[i][j]=false;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (board[i][j]<=cnt) {
                isRain[i][j]=true;
            }
        }
    }

    for (int k=0; k<n; k++) {
        for (int j=0; j<n; j++) {
            if (!isRain[k][j]&&!isVisited[k][j]){
                isVisited[k][j]=true;
                value++;

                queue<location>q;
                q.push({k,j});

                while (!q.empty()) {
                    int nx=q.front().x;
                    int ny=q.front().y;

                    q.pop();

                    for (int i=0; i<4; i++) {
                        int px=nx+dx[i];
                        int py=ny+dy[i];

                        if (isVisited[py][px]) continue;
                        if (isRain[py][px]) continue;
                        if (px<0||px>=n||py<0||py>=n) continue;
                        isVisited[py][px]=true;

                        q.push({py,px});
                    }
                }
            }
        }
    }

    return value;
}

int main() {

    int maximum=0;
    int result=0;
    cin>>n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>board[i][j];
            if (board[i][j]>maximum) maximum=board[i][j];
        }
    }
    
    for (int i=0; i<maximum; i++) {
        result=max(result,bfs(board,i));
    }
    cout<<result;
}