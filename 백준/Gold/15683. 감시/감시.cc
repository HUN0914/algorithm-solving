#include <iostream>
#include <vector>

using namespace std;

int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
int n,m;

struct cctv {
    int y;
    int x;
    char number;
};

vector<cctv>cctvs;

char board[8][8];

int maximum=1e9;

void dfs(int cnt) {

    if (cnt==cctvs.size()) {
        int curTotal=0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (board[i][j]=='0') curTotal++;
            }
        }
        maximum=min(maximum,curTotal);
        return;
    }

    for (int i=0; i<4; i++){
        int y=cctvs[cnt].y;
        int x=cctvs[cnt].x;
        char number=cctvs[cnt].number;
        char copyBoard[8][8];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                copyBoard[i][j]=board[i][j];
            }
        }

        if (number=='1') {
            while (true) {
                y+=dy[i];
                x+=dx[i];
                if (y<0||y>=n||x<0||x>=m) break;
                if (board[y][x]=='6') break;
                if (board[y][x]=='0') board[y][x]='#';
            }
        }
        else if (number=='2') {
            int newPy=y;
            int newPx=x;

            //오른쪽, 위, 왼쪽, 아래 (0,1,2,3) -> [0,2] [1,3]
            while (true) {
                newPy+=dy[i];
                newPx+=dx[i];
                if (newPy<0||newPy>=n||newPx<0||newPx>=m) break;
                if (board[newPy][newPx]=='6') break;
                if (board[newPy][newPx] =='0') board[newPy][newPx]='#';
            }

            newPy=y;
            newPx=x;
            while (true) {
                newPy+=dy[(i+2)%4];
                newPx+=dx[(i+2)%4];
                if (newPy<0||newPy>=n||newPx<0||newPx>=m) break;
                if (board[newPy][newPx]=='6') break;
                if (board[newPy][newPx] =='0') board[newPy][newPx]='#';
            }
        }
        else if (number=='3') {
            int newPy=y;
            int newPx=x;

            //오른쪽, 위, 왼쪽, 아래 (0,1,2,3) -> [0,2] [1,3]
            while (true) {
                newPy+=dy[i];
                newPx+=dx[i];
                if (newPy<0||newPy>=n||newPx<0||newPx>=m) break;
                if (board[newPy][newPx]=='6') break;
                if (board[newPy][newPx] =='0') board[newPy][newPx]='#';
            }

            newPy=y;
            newPx=x;
            while (true) {
                newPy+=dy[(i+1)%4];
                newPx+=dx[(i+1)%4];
                if (newPy<0||newPy>=n||newPx<0||newPx>=m) break;
                if (board[newPy][newPx]=='6') break;
                if (board[newPy][newPx] =='0') board[newPy][newPx]='#';
            }
        }
        else if (number=='4') {
            int newPy=y;
            int newPx=x;

            //오른쪽, 위, 왼쪽, 아래 (0,1,2,3) -> [0,2] [1,3]
            while (true) {
                newPy+=dy[i];
                newPx+=dx[i];
                if (newPy<0||newPy>=n||newPx<0||newPx>=m) break;
                if (board[newPy][newPx]=='6') break;
                if (board[newPy][newPx] =='0') board[newPy][newPx]='#';
            }

            newPy=y;
            newPx=x;
            while (true) {
                newPy+=dy[(i+1)%4];
                newPx+=dx[(i+1)%4];
                if (newPy<0||newPy>=n||newPx<0||newPx>=m) break;
                if (board[newPy][newPx]=='6') break;
                if (board[newPy][newPx] =='0') board[newPy][newPx]='#';
            }

            newPy=y;
            newPx=x;
            while (true) {
                newPy+=dy[(i+2)%4];
                newPx+=dx[(i+2)%4];
                if (newPy<0||newPy>=n||newPx<0||newPx>=m) break;
                if (board[newPy][newPx]=='6') break;
                if (board[newPy][newPx] =='0') board[newPy][newPx]='#';
            }

        }
        else if (number=='5') {
            int newPy=y;
            int newPx=x;

            //오른쪽, 위, 왼쪽, 아래 (0,1,2,3) -> [0,2] [1,3]
            while (true) {
                newPy+=dy[i];
                newPx+=dx[i];
                if (newPy<0||newPy>=n||newPx<0||newPx>=m) break;
                if (board[newPy][newPx]=='6') break;
                if (board[newPy][newPx] =='0') board[newPy][newPx]='#';
            }

            newPy=y;
            newPx=x;
            while (true) {
                newPy+=dy[(i+1)%4];
                newPx+=dx[(i+1)%4];
                if (newPy<0||newPy>=n||newPx<0||newPx>=m) break;
                if (board[newPy][newPx]=='6') break;
                if (board[newPy][newPx] =='0') board[newPy][newPx]='#';
            }

            newPy=y;
            newPx=x;
            while (true) {
                newPy+=dy[(i+2)%4];
                newPx+=dx[(i+2)%4];
                if (newPy<0||newPy>=n||newPx<0||newPx>=m) break;
                if (board[newPy][newPx]=='6') break;
                if (board[newPy][newPx] =='0') board[newPy][newPx]='#';
            }

            newPy=y;
            newPx=x;
            while (true) {
                newPy+=dy[(i+3)%4];
                newPx+=dx[(i+3)%4];
                if (newPy<0||newPy>=n||newPx<0||newPx>=m) break;
                if (board[newPy][newPx]=='6') break;
                if (board[newPy][newPx] =='0') board[newPy][newPx]='#';
            }
        }
        dfs(cnt+1);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                board[i][j]=copyBoard[i][j];
            }
        }
    }
}

void input() {
    cin>>n>>m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>board[i][j];
            if (board[i][j]!='6'&&board[i][j]!='0') {
                cctvs.push_back({i,j,board[i][j]});
            }
        }
    }
}

int main() {

    input();
    dfs(0);
    cout<<maximum;

    return 0;
}