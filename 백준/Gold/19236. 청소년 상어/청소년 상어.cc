#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Fish {
    int x, y, dir;
    bool alive;
};

int board[4][4];
Fish fishes[17];

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};

int answer = 0;

void moveFish(int sx, int sy) {
    for (int i=1; i<=16; i++) {
        if (!fishes[i].alive) continue;

        int x = fishes[i].x;
        int y = fishes[i].y;
        int dir = fishes[i].dir;

        for (int d=0; d<8; d++) {
            int nd= (dir+d)%8;
            int nx= x+dx[nd];
            int ny= y+dy[nd];

            if (nx<0||ny<0||nx>=4||ny>=4) continue;
            if (nx==sx&&ny==sy) continue;

            int target = board[nx][ny];

            board[x][y]=target;
            board[nx][ny]=i;

            fishes[i].x=nx;
            fishes[i].y=ny;
            fishes[i].dir=nd;

                fishes[target].x=x;
                fishes[target].y=y;
            break;
        }
    }
}

void dfs(int sx, int sy, int sdir, int sum) {

    answer = max(answer,sum);

    int boardBackup[4][4];
    Fish fishBackup[17];

    memcpy(boardBackup,board,sizeof(board));
    memcpy(fishBackup,fishes,sizeof(fishes));

    moveFish(sx,sy);

    for (int step=1; step<=3; step++) {
        int nx = sx + dx[sdir] * step;
        int ny = sy + dy[sdir]* step;

        if (nx<0||ny<0||nx>=4||ny>=4) continue;
        if (board[nx][ny]==0) continue;;

        int fishNum=board[nx][ny];
        int ndir = fishes[fishNum].dir;

        fishes[fishNum].alive=false;

        board[sx][sy]=0;
        board[nx][ny]=0;

        dfs(nx,ny,ndir,sum+fishNum);

        fishes[fishNum].alive=true;
        board[nx][ny]=fishNum;
    }


    memcpy(board,boardBackup,sizeof(board));
    memcpy(fishes,fishBackup,sizeof(fishes));

}

int main() {

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            int a,b;
            cin>>a>>b;
            b--;

            board[i][j]=a;
            fishes[a]={i,j,b,true};
        }
    }

    int first=board[0][0];
    board[0][0]=0;
    int dir=fishes[first].dir;
    fishes[first].alive=false;

    dfs(0,0,dir,first);

    cout<<answer;
}