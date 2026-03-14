#include <iostream>

using namespace std;

int maximum=0;

int horse[4];
int dice[10];

//score,node의 싱크를 맞추는게 핵심인 문제. score의 location과 node배열의 location 동기화
//이런문제 풀때는 다음 node정보를 담는 배열과, 점수를 담는 배열을 선언해서 동기화해주기
int score[33]={0,
    2,4,6,8,10,12,14,16,18,
    20,22,24,26,28,30,32,34,36,38,
    40,
    13,16,19,
    22,24,
    28,27,26,
    25,30,35,
    0};

int blueNode[33];
int node[33]={1,2,3,4,5,
    6,7,8,9,10,
    11,12,13,14,15,
    16,17,18,19,20,
    32,
    22,23,29,
    25,29,
    27,28,29,
    30,31,20,
    32
};

void init() {
    for (int i=0; i<33; i++) blueNode[i]=-1;
    blueNode[5]=21;
    blueNode[10]=24;
    blueNode[15]=26;
}

int moveHorse(int start, int move) {
    int cur=start;

    if (cur==32) return 32;

    for (int i=0; i<move; i++) {
        if (i==0 && blueNode[cur] !=-1) cur = blueNode[cur];
        else cur = node[cur];

        if (cur==32) break;
    }
    return cur;
}
/* node에선 다음 위치 값 담았으니 한번에 때리는게 아니라
 move 만큼 반복문 돌려가면서 위치 확인하고 위치 반환
*/

bool isOcuppied(int horseIdx, int dest) {
    if (dest==32) return false;

    for (int i=0; i<4; i++) {
        if (i== horseIdx) continue;
        if (horse[i]==dest) return true;
    }
    return false;
}

void dfs(int turn, int sum) {

    if (turn==10) {
        maximum=max(maximum,sum);
        return;
    }

    for (int i=0; i<4; i++) {
        if (horse[i]==32) continue;

        int prev=horse[i];
        int nextPos=moveHorse(prev,dice[turn]);

        if (isOcuppied(i,nextPos)) continue;

        horse[i]= nextPos;
        dfs(turn+1, sum+score[nextPos]);
        horse[i]=prev;
    }
}

int main() {
    for (int i=0; i<10; i++) cin>>dice[i];
    init();
    dfs(0,0);
    cout<<maximum;
    return 0;
}