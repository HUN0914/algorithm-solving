#include <iostream>

using namespace std;

int currBoard[500][500];

int outSand;
int N;

void moveOne(int startY, int startX) {

    int sand= currBoard[startY][startX];
    int dy[10] = {-1, 1, -1, 1, 0, -2, 2, -1, 1, 0};
    int dx[10] = { 1, 1,  0, 0, -2,  0, 0, -1,-1,-1};
    int ratio[10] = {1,1,7,7,5,2,2,10,10,0};

    int remain=sand;

    for (int i=0; i<9; i++) {
        int ny=startY+dy[i];
        int nx=startX+dx[i];
        int spread=sand*ratio[i]/100;
        remain-=spread;
        if (nx<1||nx>N||ny<1||ny>N) outSand+=spread;
        else currBoard[ny][nx]+=spread;
    }

    int ay = startY + dy[9];
    int ax = startX + dx[9];
    if (ax < 1 || ax > N || ay < 1 || ay > N)outSand += remain;
    else currBoard[ay][ax] += remain;

    currBoard[startY][startX]=0;
}

void moveTwo(int startY, int startX) {
    int sand= currBoard[startY][startX];
    int dyD[10] = {-1,-1, 0, 0, 2,  0, 0, 1, 1, 1};
    int dxD[10] = {-1, 1,-1, 1, 0, -2, 2,-1, 1, 0};
    int ratio[10] = {1,1,7,7,5,2,2,10,10,0};

    int remain=sand;

    for (int i=0; i<9; i++) {
        int ny=startY+dyD[i];
        int nx=startX+dxD[i];
        int spread=sand*ratio[i]/100;
        remain-=spread;
        if (nx<1||nx>N||ny<1||ny>N) outSand+=spread;
        else currBoard[ny][nx]+=spread;
    }

    int ay = startY + dyD[9];
    int ax = startX + dxD[9];
    if (ax < 1 || ax > N || ay < 1 || ay > N)outSand += remain;
    else currBoard[ay][ax] += remain;

    currBoard[startY][startX]=0;
}

void moveThree(int startY, int startX) {

    int sand= currBoard[startY][startX];
    int dyR[10] = {-1, 1, -1, 1, 0, -2, 2, -1, 1, 0};
    int dxR[10] = {-1,-1,  0, 0, 2,  0, 0,  1, 1, 1};
    int ratio[10] = {1,1,7,7,5,2,2,10,10,0};

    int remain=sand;

    for (int i=0; i<9; i++) {
        int ny=startY+dyR[i];
        int nx=startX+dxR[i];
        int spread=sand*ratio[i]/100;
        remain-=spread;
        if (nx<1||nx>N||ny<1||ny>N) outSand+=spread;
        else currBoard[ny][nx]+=spread;
    }

    int ay = startY + dyR[9];
    int ax = startX + dxR[9];
    if (ax < 1 || ax > N || ay < 1 || ay > N)outSand += remain;
    else currBoard[ay][ax] += remain;

    currBoard[startY][startX]=0;
}

void moveFour(int startY, int startX) {

    int sand= currBoard[startY][startX];
    int dyU[10] = { 1, 1, 0, 0,-2, 0, 0,-1,-1,-1};
    int dxU[10] = {-1, 1,-1, 1, 0,-2, 2,-1, 1, 0};

    int ratio[10] = {1,1,7,7,5,2,2,10,10,0};

    int remain=sand;

    for (int i=0; i<9; i++) {
        int ny=startY+dyU[i];
        int nx=startX+dxU[i];
        int spread=sand*ratio[i]/100;
        remain-=spread;
        if (nx<1||nx>N||ny<1||ny>N) outSand+=spread;
        else currBoard[ny][nx]+=spread;
    }

    int ay = startY + dyU[9];
    int ax = startX + dxU[9];
    if (ax < 1 || ax > N || ay < 1 || ay > N)outSand += remain;
    else currBoard[ay][ax] += remain;

    currBoard[startY][startX]=0;
}

void game() {

    int startY=(N/2)+1;
    int startX=(N/2)+1;
    int dir=0;
    int len=1;

    while (true) {

        for (int t=0 ;t<2; t++) {
            dir=dir%4;
            for (int i=0; i<len; i++) {

                if (startX==1&&startY==1) return;
                if (dir==0) {
                    startX--;
                    moveOne(startY,startX);
                }
                if (dir==1) {
                    startY++;
                    moveTwo(startY,startX);
                }
                if (dir==2) {
                    startX++;
                    moveThree(startY,startX);
                }
                if (dir==3) {
                    startY--;
                    moveFour(startY,startX);
                }
            }
            dir++;
        }
        len++;
    }
}

void input() {
    cin>>N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            cin>>currBoard[i][j];
    }
    game();
}

int main() {
    input();
    cout<<outSand;
    return 0;
}