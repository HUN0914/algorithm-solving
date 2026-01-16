#include <iostream>
#include <vector>

using namespace std;

struct fireball {
    int r,c,m,s,d;
};

int N,M,K;
vector<fireball>fireballs;

int dr[8] = {-1,-1, 0, 1, 1, 1, 0,-1};
int dc[8] = { 0, 1, 1, 1, 0,-1,-1,-1};

void input() {
    cin>>N>>M>>K;

    for (int i=0; i<M; i++) {
        int r,c,m,s,d;
        cin>>r>>c>>m>>s>>d;
        fireballs.push_back({r-1,c-1,m,s,d});
    }
}

void merging(vector<vector<vector<fireball>>> fireballMap) {
    vector<fireball> ballList;

    for (int r=0; r<N; r++) {
        for (int c=0; c<N; c++) {
            auto &cell = fireballMap[r][c];
            if (cell.empty()) continue;

            if (cell.size()==1) {
                ballList.push_back(cell[0]);
                continue;
            }

            int sumM=0; int sumS=0;
            bool allDigit=true, allNotDigit=true;

            for (auto& ball : cell) {
                sumM+=ball.m;
                sumS+=ball.s;
                if (ball.d%2==0) allNotDigit=false;
                else allDigit=false;
            }
            int newM=sumM/5;
            if (newM == 0) continue;
            int newS=sumS/(int)cell.size();
            if (allDigit || allNotDigit) {
                for (int i=0; i<8; i+=2) {
                    ballList.push_back({r,c,newM,newS,i});
                }
            }else {
                for (int i=1; i<9; i+=2) {
                    ballList.push_back({r,c,newM,newS,i});
                }
            }
        }
    }
    fireballs.swap(ballList);
}

void move() {
    vector<vector<vector<fireball>>> fireballMap(N,vector<vector<fireball>>(N));

    for (auto & ball : fireballs) {
        int moveS=ball.s%N;
        ball.r=(ball.r+moveS*dr[ball.d]+N)%N;
        ball.c=(ball.c+moveS*dc[ball.d]+N)%N;
        fireballMap[ball.r][ball.c].push_back(ball);
    }
    merging(fireballMap);
}

void game() {

    int result=0;

    input();
    for (int i=0; i<K; i++) {
        move();
    }

    for (auto& ball :fireballs){
        result+=ball.m;
    }
    cout<<result;
}
int main() {
    game();
}