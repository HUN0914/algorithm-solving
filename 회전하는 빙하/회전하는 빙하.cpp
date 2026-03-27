#include <iostream>
#include <queue>

using namespace std;

int copyboard[65][65];
int board[65][65];

bool isVisited[65][65];

int n,q;
int space=1;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

int total=0;
int curGroupCnt=0;

struct info {
    int locationY=0;
    int locationX=0;
};

void nearIce() {

    for (int i=0; i<space; i++)
        for (int j=0; j<space; j++) copyboard[i][j]=board[i][j];

    for (int i=0; i<space; i++) {
        for (int j=0; j<space; j++) {
            if (board[i][j]==0) continue;
            int nearCnt=0;

            for (int k=0; k<4; k++) {
                int py=i+dy[k];
                int px=j+dx[k];

                if (py<0||py>=space||px<0||px>=space) continue;
                if (board[py][px]>0) nearCnt++;
            }

            if (nearCnt<3) copyboard[i][j]--;
        }
    }

    for (int i=0; i<space; i++)
        for (int j=0; j<space; j++) board[i][j]=copyboard[i][j];
}

void sumIce() {
    for (int i=0; i<space; i++)
        for (int j=0; j<space; j++) total+=board[i][j];
}

void findIce() {

    queue<info>q;

    for (int i=0; i<space; i++) {
        for (int j=0; j<space; j++) {
            if (board[i][j]==0) continue;

            for (int aa=0; aa<space; aa++)
                for (int bb=0; bb<space; bb++) isVisited[aa][bb]=false;

            isVisited[i][j]=true;

            q.push({i,j});

            int size=1;

            while (!q.empty()) {

                int ny=q.front().locationY;
                int nx=q.front().locationX;

                q.pop();

                for (int k=0; k<4; k++) {
                    int py=ny+dy[k];
                    int px=nx+dx[k];

                    if (py<0||py>=space||px<0||px>=space) continue;
                    //이거 continue하는게 아니라
                    if (isVisited[py][px]) continue;
                    if (board[py][px]==0) continue;

                    isVisited[py][px]=true;
                    size++;

                    q.push({py,px});
                }
            }

            curGroupCnt=max(curGroupCnt,size);
        }
    }
}

void moveRight(int sr, int sc, int halfSize){

    for (int i=sr; i<sr+halfSize; i++) {
        for (int j=sc; j<sc+halfSize; j++) {
            copyboard[i][j+halfSize]=board[i][j];
        }
    }
}

void moveDown(int sr, int sc, int halfSize){

    for (int i=sr; i<sr+halfSize; i++) {
        for (int j=sc; j<sc+halfSize; j++) {
            copyboard[i+halfSize][j]=board[i][j];
        }
    }
}

void moveLeft(int sr, int sc, int halfSize) {

    for (int i=sr; i<sr+halfSize; i++) {
        for (int j=sc; j<sc+halfSize; j++) {
            copyboard[i][j-halfSize]=board[i][j];
        }
    }
}

void moveUp(int sr, int sc, int halfSize) {

    for (int i=sr; i<sr+halfSize; i++) {
        for (int j=sc; j<sc+halfSize; j++) {
            copyboard[i-halfSize][j]=board[i][j];
        }
    }
}

void boardToCopyBoard(){
    for(int i=0; i<space; i++)
        for(int j=0; j<space; j++) board[i][j]=copyboard[i][j];
}

void copyBoardToBoard(){
    for(int i=0; i<space; i++)
        for(int j=0; j<space; j++) copyboard[i][j]=board[i][j];
}

void rotate(int level){

    int rotateSpace=1;

    for(int i=1; i<=level; i++) rotateSpace*=2;
    copyBoardToBoard();

    for(int i=0; i<space; i+=rotateSpace){ // 세로값 기준
        for (int j=0; j<space; j+=rotateSpace) {
            int halfValue=rotateSpace/2;
            moveRight(i,j,halfValue);
            moveDown(i,j+halfValue,halfValue);
            moveLeft(i+halfValue,j+halfValue,halfValue);
            moveUp(i+halfValue,j,halfValue);
        }
    }
    boardToCopyBoard();
}

void game(int level) {
    rotate(level);
    nearIce();
}

void input(){

    cin>>n>>q;

    for(int i=1; i<=n; i++) space*=2;

    for(int i=0; i<space; i++)
        for(int j=0; j<space; j++) cin>>board[i][j];

    for (int i=0; i<q; i++) {
        int curLevel;
        cin>>curLevel;
        game(curLevel);
    }

}

int main() {
    input();
    findIce();
    sumIce();
    cout<<total<<"\n"<<curGroupCnt;

    return 0;
}

/*

rotate의 기준
lv 1 이면 2 ^ 1 = 2
lv 2 이면 2 ^ 2 = 4 (이게 기준)

회전을 어떻게 하는거지?
- level 0일땐 회전 X
- level 1일땐 2*2내에서 돌아버림
- level 2일땐 2^2*2^2(4*4) 범위에서 2*2짜리 범주로 돌아버림
- 마찬가지로 level 3일땐 2^3*2^3(8*8) 범위에서 2^2*2^2 (4*4) 범주로 돌아버릴듯

뭐든 4방향으로 가는 로직을 만들면됨
n=1 일때 2*2잖아. => board[0][1]=copyboard[0][0] | board[0][0]= copyboard[1][0];

*/
