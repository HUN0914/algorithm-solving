#include <iostream>

using namespace std;

int R,C,T;
int currBoard[51][51];
int copyBoard[51][51];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

int upCleanerLocationY=-1;
int upCleanerLocationX=-1;

int downCleanerLocationY=-1;
int downCleanerLocationX=-1;

void mergeCurrAndCopy() {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            currBoard[i][j]=copyBoard[i][j];
        }
    }
}

void mergeCopyAndCurr() {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            copyBoard[i][j]=currBoard[i][j];
        }
    }
}

void spread() {

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            copyBoard[i][j]=0;
        }
    }

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (currBoard[i][j]>0) {
                int spreadCount=0;
                for (int k=0; k<4; k++) {
                    int ny=i+dy[k];
                    int nx=j+dx[k];
                    if (ny<0||ny>=R||nx<0||nx>=C||currBoard[ny][nx]==-1) continue;
                    copyBoard[ny][nx]+=currBoard[i][j]/5;
                    spreadCount++;
                }
                copyBoard[i][j]+=currBoard[i][j]-((currBoard[i][j]/5)*spreadCount);
            }
        }
    }
    copyBoard[upCleanerLocationY][upCleanerLocationX] = -1;
    copyBoard[downCleanerLocationY][downCleanerLocationX] = -1;
    mergeCurrAndCopy();
}

//모든 전제는 다 돌아서 청정기 위치까지 왔을때라는 가정
void upCleaning() {

    bool up=false;
    bool down=false;
    bool left=false;
    bool right=false;
    int startY=upCleanerLocationY;
    int startX=upCleanerLocationX+1;

    while (true) {

        if (up&&down&&left&&right) break;

        if (!right) {
            if (startX==C-1) right=true;
            else {
                currBoard[startY][startX+1]=copyBoard[startY][startX];
                startX++;
            }
        }
        if (!up&&right) {
            if (startY==0) up=true;
            else {
                currBoard[startY-1][startX]=copyBoard[startY][startX];
                startY--;
            }
        }
        if (!left&&up&&right) {
            if (startX==0) left=true;
            else {
                currBoard[startY][startX-1]=copyBoard[startY][startX];
                startX--;
            }
        }
        if (!down&&left&&up&&right) {
            if (startY+1==upCleanerLocationY) {
                down=true;
            }else {
                currBoard[startY+1][startX]=copyBoard[startY][startX];
                startY++;
            }
        }
    }
    currBoard[upCleanerLocationY][upCleanerLocationX+1] = 0;
    mergeCopyAndCurr();
    copyBoard[upCleanerLocationY][upCleanerLocationX] = -1;
    copyBoard[downCleanerLocationY][downCleanerLocationX] = -1;
}

void downCleaning() {
    bool up=false;
    bool down=false;
    bool left=false;
    bool right=false;
    int startY=downCleanerLocationY;
    int startX=downCleanerLocationX+1;

    while (true) {

        if (up&&down&&left&&right) break;

        if (!right) {
            if (startX==C-1) right=true;
            else {
                currBoard[startY][startX+1]=copyBoard[startY][startX];
                startX++;
            }
        }
        if (!down&&right) {
            if (startY==R-1) {
                down=true;
            }else {
                currBoard[startY+1][startX]=copyBoard[startY][startX];
                startY++;
            }
        }
        if (!left&&down&&right) {
            if (startX==0) left=true;
            else {
                currBoard[startY][startX-1]=copyBoard[startY][startX];
                startX--;
            }
        }
        if (!up&&left&&down&&right) {
            if (startY-1==downCleanerLocationY) up=true;
            else {
                currBoard[startY-1][startX]=copyBoard[startY][startX];
                startY--;
            }
        }
    }
    currBoard[downCleanerLocationY][downCleanerLocationX+1] = 0;
    mergeCopyAndCurr();
}

void game(int T) {
    for (int i=0 ;i<T; i++) {
        spread();
        upCleaning();
        downCleaning();
    }

}

void input() {
    cin>>R>>C>>T;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin>>currBoard[i][j];
            copyBoard[i][j]=currBoard[i][j];
            if (currBoard[i][j]==-1) {
                if (upCleanerLocationY!=-1&&upCleanerLocationX!=-1) {
                    downCleanerLocationY=i;
                    downCleanerLocationX=j;
                }else {
                    upCleanerLocationY=i;
                    upCleanerLocationX=j;
                }
            }
        }
    }

    game(T);
}

void total() {
    int sum=0;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (currBoard[i][j]!=-1) sum+=currBoard[i][j];
        }
    }

    cout<<sum;
}

int main() {
    input();
    total();
}