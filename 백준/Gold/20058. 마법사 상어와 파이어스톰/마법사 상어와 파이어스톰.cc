#include <iostream>
#include <queue>
using namespace std;

bool isVisited[64][64];
int currBoard[64][64];
int changingBoard[64][64];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int n,q,l;
int value;
int maximum=0;
void mergeChangingBoard() {

    for (int i=0; i<value; i++) {
        for (int j=0; j<value; j++) {
            currBoard[i][j]=changingBoard[i][j];
        }
    }
}

void mergeCurrBoard() {
    for (int i=0; i<value; i++) {
        for (int j=0; j<value; j++) {
            changingBoard[i][j]=currBoard[i][j];
        }
    }
}
//시계방향 [sy+j][sx+k-1-i]
void changing(int len) {
    int k = 1<<len;

    for (int i=0; i<value; i++)
        for (int j=0; j<value; j++)
            changingBoard[i][j] = 0;

    for (int sy=0; sy<value; sy+=k) {
        for (int sx=0; sx<value; sx+=k) {
            for (int i=0; i<k; i++) {
                for (int j=0; j<k; j++) {
                    changingBoard[sy+j][sx+k-1-i]=currBoard[sy+i][sx+j];
                }
            }
        }
    }
    mergeChangingBoard();
}

void checkIce() {

    mergeCurrBoard();

    for (int i=0; i<value; i++) {
        for (int j=0; j<value; j++) {
            int iceCount=0;
            for (int k=0; k<4; k++){
                int ny=i+dy[k];
                int nx=j+dx[k];
                if (ny>=value||ny<0||nx>=value||nx<0) continue;
                if (currBoard[ny][nx]>=1) iceCount++;
            }
            if (iceCount<3&&currBoard[i][j]>0) changingBoard[i][j]--;
        }
    }

    mergeChangingBoard();
}

void bfs(int i, int j) {
    queue<pair<int,int>>q;

    q.push({i,j});
    isVisited[i][j]=true;
    int cnt=1;
    while (!q.empty()) {
        int ny=q.front().first;
        int nx=q.front().second;

        q.pop();

        for (int i=0; i<4; i++) {
            int py=ny+dy[i];
            int px=nx+dx[i];
            if (py<0||py>=value||px<0||px>=value) continue;
            if (isVisited[py][px]) continue;
            if (currBoard[py][px]==0) continue;
            isVisited[py][px]=true;
            q.push({py,px});
            cnt++;
        }
    }
    maximum=max(maximum,cnt);
}

void calculate() {
    int result=0;

    for (int i=0; i<value; i++) {
        for (int j=0; j<value; j++) {
            if (currBoard[i][j] > 0 && !isVisited[i][j]) {
                bfs(i, j);
            }
        }
    }

    for (int i=0; i<value; i++) {
        for (int j=0; j<value; j++) {
            result+=currBoard[i][j];
        }
    }

    cout<<result<<"\n"<<maximum;

}

void input() {
    cin>>n>>q;
    value=1<<n;
    for (int i=0; i<value; i++)
        for (int j=0; j<value; j++) cin>>currBoard[i][j];

    for (int i=0; i<q; i++) {
        cin>>l;
        changing(l);
        checkIce();
    }
}


int main() {

    input();
    calculate();
}
