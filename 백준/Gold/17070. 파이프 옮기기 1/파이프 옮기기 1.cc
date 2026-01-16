#include <iostream>

using namespace std;

int dy[3]={0,1,1};
int dx[3]={1,1,0};
int board[17][17];
int n;
int answer;

void dfs(int y, int x, int dir) {

    if (x==n-1&&y==n-1) {
        answer++;
        return;
    }

    if (dir==0) {
        for (int i=0; i<2; i++) {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if (ny<0||ny>=n||nx<0||nx>=n) continue;
            if (board[ny][nx]==1) continue;
            if (i==0) {
                dfs(ny,nx,i);
            }else {
                if (board[y+1][x]!=1&&board[y][x+1]!=1) {
                    dfs(ny,nx,i);
                }
            }
        }
    }else if (dir==1) {
        for (int i=0; i<3; i++) {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if (ny<0||ny>=n||nx<0||nx>=n) continue;
            if (board[ny][nx]==1) continue;

            if (i==1) {
                if (board[y+1][x]!=1&&board[y][x+1]!=1) {
                    dfs(ny,nx,i);
                }
            }else {
                dfs(ny,nx,i);
            }
        }
    }else if (dir==2) {
        for (int i=1; i<3; i++) {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if (ny<0||ny>=n||nx<0||nx>=n) continue;
            if (board[ny][nx]==1) continue;
            if (i==1) {
                if (board[y+1][x]!=1&&board[y][x+1]!=1) {
                    dfs(ny,nx,i);
                }
            }else {
                dfs(ny,nx,i);
            }
        }
    }

}

void input() {

    cin>>n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>board[i][j];
        }
    }

}

void game() {
    input();
    dfs(0,1,0);
    cout<<answer;
}

int main() {
    game();
    return 0;
}