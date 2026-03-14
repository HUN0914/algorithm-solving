#include <iostream>
#include <vector>

using namespace std;

int player[50][9]; //1배열 : 이닝 / 2배열 : 점수 (기본적 counting : 선수10명)
vector<int> playerList;
bool isVisited[9];
int n;
int maximum=0;

void game() {

    int score=0;
    int curPlayer=0;
    for (int i=0; i<n; i++) {
        int base[4];
        for (int j=0; j<4; j++) base[j]=0;
        int outCount=0;

        while (true){
            curPlayer%=9;

            int value = player[i][playerList[curPlayer]];

            if (value==0) outCount++;
            else if (value==1) {
                score+=base[3];
                base[3]=base[2];
                base[2]=base[1];
                base[1]=1;
            }else if (value==2) {
                score+=base[3]+base[2];
                base[3]=base[1];
                base[2]=1;
                base[1]=0;
            }else if (value==3) {
                score+=base[3]+base[2]+base[1];
                base[3]=1;
                base[2]=0;
                base[1]=0;
            }else if (value==4) {
                score+=base[3]+base[2]+base[1]+1;
                base[3]=0;
                base[2]=0;
                base[1]=0;
            }
            if (outCount>=3) {
                curPlayer=(curPlayer+1)%9;
                break;
            }
            curPlayer++;
        }
    }

    maximum=max(score,maximum);
}

void orderInit(int cnt) {
    if (cnt==9) {
        game();
        return;
    }

    if (cnt==3) {
        playerList.push_back(0);
        orderInit(cnt+1);
        playerList.pop_back();
        return;
    }

    for (int i=1; i<9; i++) {
        if (isVisited[i]) continue;
        isVisited[i]=true;
        playerList.push_back(i);
        orderInit(cnt+1);
        isVisited[i]=false;
        playerList.pop_back();
    }
}

void input() {
    cin>>n;
    for (int i=0; i<n; i++)
        for (int j=0; j<9; j++) cin>>player[i][j];
}

int main() {
    input();
    orderInit(0);

    cout<<maximum;
    return 0;
}

/*
 * 이닝 끝나면 그 끝난 번호에서 다음 번호부터 진행을 함
 * 번호는 각 이닝마다의 내가 낼 수 있는 점수를 의미
 * 1번 선수를 무조건 4번 타자로 지정 (초기 이닛값)
 * 모든 플레이어 순서 경우의 수를 두고 9*8*7*5*4*3*2 -> 이거 저장할 벡터부터 지정
 * 그때의 이닝값들 다 계산해서 max 값 반환
 */