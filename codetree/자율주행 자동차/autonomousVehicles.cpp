#include <iostream>
#include <queue>

using namespace std;

int n,m;
int board[51][51];
int copyBoard[51][51];
bool isVisited[51][51];

struct car {
    int locationY;
    int locationX;
    int checkCnt;
};

int dir; // [0:북쪽] [1:동쪽] [2:남쪽] [3:서쪽]

int py[4]={-1,0,1,0};
int px[4]={0,1,0,-1};

int locationY;
int locationX;

void calSpace() {

    // for (int i=0;i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         if (isVisited[i][j]) {
    //             cout<<" O ";
    //         }else cout<<" X ";
    //     }
    //     cout<<"\n";
    // }

    int total=0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (isVisited[i][j]) total++;
        }
    }

    cout<<total;
}

void checkSpace(int curLocationY, int curLocationX, int dir) {

    queue<car>q;

    q.push({curLocationY,curLocationX, 0});
    isVisited[curLocationY][curLocationX]=true;

    while (!q.empty()) {

        int y=q.front().locationY;
        int x=q.front().locationX;
        int curCheckCnt=q.front().checkCnt;
        q.pop();
       // cout<<"curY: "<<y<<" curX: "<<x<<"\n";

        if (curCheckCnt==4) {
            int ny=y-py[dir%4];
            int nx=x-px[dir%4];
            if (ny<0||ny>=n
                ||nx<0||nx>=m
                ||board[ny][nx]==1) return;

            q.push({ny,nx,0});
            continue;
        }

        dir=(dir+3)%4;//0 - > 3 (북-서) -> 6%4=2 남 -> 1(동)

        int ny=y+py[dir];
        int nx=x+px[dir];

        if (board[ny][nx]==1||isVisited[ny][nx]==true||ny<0||ny>=n||nx<0||nx>=m) {
            curCheckCnt++;
            /*
             [0:북쪽] [1:동쪽] [2:남쪽] [3:서쪽]
             0(북) -> 0+3 % 4 = 3 (서)
             3+ 3 % 4 = 2 (남)

             */
            q.push({y,x,curCheckCnt});
        }else {
            isVisited[ny][nx]=true;
            q.push({ny,nx,0});
        }
    }
}

void input() {
    //0은 도로, 1은 인도 의미
    cin>>n>>m;
    cin>>locationY>>locationX>>dir;

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) cin>>board[i][j];

    checkSpace(locationY,locationX,dir);
    calSpace();
}

int main() {
    input();

    return 0;
}
