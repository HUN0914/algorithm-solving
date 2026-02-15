#include <iostream>

using namespace std;

bool isLine[31][11];
int n,m,h;
bool flag;

void dfs(int cnt, int ladderCnt, int init ) {
    if (cnt==ladderCnt) {
       bool isAnswer=true;
        for (int i=1; i<=n; i++) {
            int verti=i;
            for (int j=1; j<=h; j++) {
                if (isLine[j][verti]) verti++;
                else if (verti>1 && isLine[j][verti-1]) verti--;
            }
            if (verti!=i) {
                isAnswer=false;
                break;
            }
        }
        if (isAnswer) flag=true;
        return;
    }

    for (int i=init; i<=h; i++) {
        for (int j=1; j<n; j++) {
            if (!isLine[i][j]&&!isLine[i][j+1]&&!isLine[i][j-1]) {
                isLine[i][j]=true;
                dfs(cnt+1,ladderCnt,i);
                isLine[i][j]=false;
            }
        }
    }
}

void input() {
    cin>>n>>m>>h;

    while (m--) {
        int garo, sero;
        cin>>garo>>sero;
        isLine[garo][sero]=true;
    }
}

void game() {
    int ladderCnt=0;
    for (int i=0; i<=3; i++) {
        dfs(0,ladderCnt,1);
        if (flag) {
            cout<<ladderCnt;
            return;
        }
        ladderCnt++;
    }
    cout<<-1;
}

int main() {

    input();
    game();

    return 0;
}

/*
 일단 dfs로 모든 곳에 사다리를 놔버림.
 그리고 그 경우에 대해서 모두 t/f검사
 */