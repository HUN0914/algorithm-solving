#include <iostream>

using namespace std;
int board[51][51];
int copyBoard[51][51];
int t;
int n,m;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

int upDustY=-1;
int downDustY=-1;

void boardToCopyBoard() {
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) board[i][j]=copyBoard[i][j];
}

void copyBoardToBoard() {
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) copyBoard[i][j]=board[i][j];
}
/*
1. 먼지 확산 (상하좌우)
    인접 방향에 돌풍 있거나 범위 벗어나면 먼지 확산 X
    확산되는 양은 원래 칸의 먼지의 양에 5를 나눈 값이며 편의상 소숫점은 버림
    각 칸 확산될때마다 원래 먼지 양은 확산된 양만큼 줄어듬
    확산된 먼지는 방에 있는 [모든 먼지가 확산을 끝낸] 다음 해당 칸에 더해지게 됨
 */
void spreadDust() {
    copyBoardToBoard();

    //test 여기서 내가 주석친 코드 왜 틀렸는지 GPT한테 물어보기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            copyBoard[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] < 5) continue;

            int divFive = board[i][j] / 5;

            for (int k = 0; k < 4; k++) {
                int py = i + dy[k];
                int px = j + dx[k];

                if (py < 0 || py >= n || px < 0 || px >= m) continue;
                if (board[py][px] == -1) continue;

                copyBoard[py][px] += divFive;
                copyBoard[i][j] -= divFive;
                //copyBoard[py][px]=copyBoard[py][px]+divFive;
                //board[i][j]=board[i][j]-divFive;
            }

            //copyBoard[i][j]=board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] += copyBoard[i][j];
        }
    }
    //boardToCopyBoard();
}

void cleanUpDust(int startY) {

    copyBoardToBoard();

    //right
    for (int i=0; i<m-1; i++) copyBoard[startY][i+1]=board[startY][i];
    //up
    for (int i=startY; i>0; i--) copyBoard[i-1][m-1]=board[i][m-1];

    //left
    for (int i=m-1; i>0; i--) copyBoard[0][i-1]=board[0][i];
    //down
    for (int i=0; i<startY-1; i++) copyBoard[i+1][0]=board[i][0];

    copyBoard[startY][1]=0;
    boardToCopyBoard();
}

void cleanDownDust(int downY) {
    //right
    for (int i=0; i<m-1; i++) copyBoard[downY][i+1]=board[downY][i];
    //down
    for (int i=downY; i<n-1; i++) copyBoard[i+1][m-1]=board[i][m-1];
    //left
    for (int i=m-1; i>0; i--) copyBoard[n-1][i-1]=board[n-1][i];
    //up
    for (int i=n-1; i>downY+1; i--) copyBoard[i-1][0]=board[i][0];

    copyBoard[downY][1]=0;
    // cout<<"\n";
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         cout<<copyBoard[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    boardToCopyBoard();
}

void sumTotal() {
    int total=0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (board[i][j]==-1) continue;
            total+=board[i][j];
        }
    }

    //test
    // cout<<"\n";
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         cout<<board[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    //
     cout<<total;
}


void game(int t) {

    for (int i=0; i<t; i++) {
        spreadDust();
        cleanUpDust(upDustY);
        cleanDownDust(downDustY);
    }
    sumTotal();
}


void input() {

    cin>>n>>m>>t;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>board[i][j];
            if (board[i][j]==-1) {
                if (upDustY==-1) upDustY=i;
                else downDustY=i;
            }
        }
    }

    game(t);
}

int main() {
    input();
    return 0;
}

/*
 1. 먼지 확산 (상하좌우)
    인접 방향에 돌풍 있거나 범위 벗어나면 먼지 확산 X
    확산되는 양은 원래 칸의 먼지의 양에 5를 나눈 값이며 편의상 소숫점은 버림
    각 칸 확산될때마다 원래 먼지 양은 확산된 양만큼 줄어듬
    확산된 먼지는 방에 있는 [모든 먼지가 확산을 끝낸] 다음 해당 칸에 더해지게 됨

 2. 시공의 돌풍이 청소 시작
    시공의 돌풍 윗칸에선 반시계 방향 일으킴 / 아래칸에선 시계 방향으로 바람 일으킴
    바람 불면 먼지가 바람의 방향대로 모두 한 칸씩 이동
    바람  불면 먼지가 발마 방향대로 모두 한 칸씩 이동
    시공 돌풍에서 나온 바람은 먼지 없는 바람. 시공 돌풍 들어간 먼지 사라짐


 만들어야 할 함수
  1. 먼지 확산 함수
    1.1 먼지 확산 시 copyBoard에 자신이 줄어든 값만큼과 남 추가한 만큼 추가
  2. 돌풍 함수
    2.1 moveright, moveup, moveleft, movedown 만들어주면됨
    2.2 이거또한 copyboard로 해주면됨
 */
