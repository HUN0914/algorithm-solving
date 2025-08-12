#include <iostream>
#include <queue>

using namespace std;

int N,K;
int L;
int boards[101][101];
char direct_information[10001];
bool visited[500][500];

/*
    북 =0, 동=1,남=2,서=3 이라 했을 때
    만약 'D'이면 d+1%4
    만약 'L'이면 d+3%4
    몸 기록을 어떻게 하냐?? 흠..
    몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
    => 원래 매초마다 몸길이가 늘어났는데 지금은 -1+1=0 이란 의미네
*/

int direct(int d, char C) {
    if (C=='L') {
        return (d+3)%4;
    }
    return (d+1)%4;
}

int game() {


    int x=1;
    int y=1;
    int curr_direct=1;
    int timer=0;

    queue<pair<int,int>>q;
    q.push({1,1});

    while (true) {
        if (visited[y][x]==true||y>N||x>N||y<=0||x<=0) return timer;

        visited[y][x]=true;

        if (boards[y][x]!=1) {
            int tail_y= q.front().first;
            int tail_x=q.front().second;
            visited[tail_y][tail_x]=false;
            q.pop();
        } else {
            boards[y][x]=0;
        }

        q.push({y,x});

        if (direct_information[timer]=='D'||direct_information[timer]=='L') {
            char change_direct=direct_information[timer];
            curr_direct=direct(curr_direct,change_direct);
        }

        //북 =0, 동=1,남=2,서=3
        if (curr_direct==0) {
            y--;
        }
        if (curr_direct==1) {
            x++;
        }
        if (curr_direct==2) {
            y++;
        }
        if (curr_direct==3) {
            x--;
        }
        timer++;
    }
}

int main() {

    int col, row;
    int X;
    char C;

    cin>>N;
    cin>>K;

    for (int i=0; i<K; i++) {
        cin>>col>>row;
        boards[col][row]=1;
    }


    cin>>L;

    for (int i=0; i<L; i++) {
        cin>>X>>C;
        direct_information[X]=C;
    }

    int result_time=game();
    cout<<result_time;

    return 0;
}

/*
 * 뱀의 초기 길이는 1이고 오른쪽을 향함
 * 뱀은 매 초 이동하는데 1초마다 아래와 같은 규칙을 따름.
 * 몸 길이 늘려서 '머리'를 다음칸에 위치
 * 벽이나 자기자신의 몸과 부딪히면 게임 끝
 * 이동한 칸에 사과 있으면 사과 없어지고 '꼬리' 안 움직임
 * 이동한 칸에 사과 없으면 몸길이 줄여서 꼬리가 위치한 칸을 비워줌
 * 즉, '몸 길이(꼬리 제외한게 몸길이 인듯)' 변하지 않음
 *
 * 처음 보드의 크기 N (1인덱스)
 * 다음 사과의 개수 K 주어짐
 * 그 다음 K줄에 사과의 위치 주어짐 (첫번째가 행(열X)임!)
 * 그 다음 뱀의 방향전환 횟수 L
 * 다음 L개의 줄에 뱀의 방향전환 정보 (정수 X 문자 C로 구성)
 * X초가 끝난 뒤에 왼(L) 혹은 오른(C)쪽으로 90도 방향 회전한다는 의미
 */