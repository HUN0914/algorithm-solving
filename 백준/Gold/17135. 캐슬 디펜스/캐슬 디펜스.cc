#include <iostream>
#include <set>
#include <vector>

using namespace std;

int board[15][15];
int copyboard[15][15];
bool isVisited[15]; //한 성마다 궁수 한명만 존재 가능
vector<int> sniperLocation;
int n,m,d;

int maximum=0;
int curMax=0;
set<pair<int,int>>s;

bool searchEnemy() {
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (board[i][j]==1) return true;

    return false;
}

void moveEnemy() {

    for (auto p : s) {
        int y=p.first;
        int x=p.second;
        board[y][x]=0;
        curMax++;
    }
    s.clear();

    for (int j=0; j<m; j++) board[n-1][j]=0;

    for (int i=n-2; i>=0; i--) {
        for (int j=0; j<m; j++) {
            if (board[i][j]==1) {
                board[i][j]=0;
                board[i+1][j]=1;
            }
        }
    }
}


void removeEnemy() {

    for (int i=0; i<3; i++) {
        int x=sniperLocation[i];
        int curDistance=987654321;
        int leftY=987654321;
        int leftX=-987654321;
        //제일 왼쪽 : k-x (abs안하고)가 가장 작은값

        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++) {
                if (board[j][k]==1){
                    if (abs(abs(j-n)+abs(k-x))<=d) {
                        if (curDistance>abs(abs(j-n)+abs(k-x))) {
                            leftY=j;
                            leftX=k;
                            curDistance=abs(abs(j-n)+abs(k-x));
                            continue;
                        }
                        if (curDistance==abs(abs(j-n)+abs(k-x))) {
                            if (leftX>k) {
                                leftY=j;
                                leftX=k;
                            }
                        }
                    }
                }
            }
        }
        if (leftY!=987654321&&leftX!=987654321) s.insert({leftY,leftX});
    }
    moveEnemy();
}

void dfsSniper(int cnt) {
    if (cnt==3) {
       curMax=0;
        while (searchEnemy()) {
            removeEnemy();
        }
        maximum=max(maximum,curMax);
        return;
    }

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) copyboard[i][j]=board[i][j];

    for (int k=0; k<m; k++) {
        if (isVisited[k]) continue;
        isVisited[k]=true;
        sniperLocation.push_back(k);
        dfsSniper(cnt+1);

        for (int j=0; j<n; j++)
            for (int k=0; k<m; k++) board[j][k]=copyboard[j][k];

        isVisited[k]=false;
        sniperLocation.pop_back();
    }

}

void input() {
    cin>>n>>m>>d;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) cin>>board[i][j];
}

int main() {

    input();
    dfsSniper(0);
    cout<<maximum;

    return 0;
}

/*
 이런 문제 풀 때 맵 copy해주는거 잊지않기
 1. 궁수 3명 모든 곳에 놓고 dfs 돌리면 됨
 1. 궁수 3명 dfs 두기
 1-1. 거리 내에 모든 애들 탐색 (그 중 맨 왼쪽꺼 선택) 후 제거 (cnt++)
 1-2. 적 아래로 이동
 1-3. 완탐으로 전부 0일 경우 break

 궁수 3명 배치
 각 턴마다 궁수는 적 하나 공격 가능
 모든 궁수 동시에 공격
 궁수 공격하는 적은 거리가 D 이하 적 중 가장 가까운 적
 여럿일 경우 가장 왼쪽에 있는 적
 같은 적이 여러 궁수에게 공격당할수 O
 공격받은 적 게임 제외
 궁수 공격 끝나면 적 이동
 적 아래로 한칸 이동
 성이 있는 칸으로 이동한 경우 게임 제외
 모든 적 제외되면 게임 끝
 */