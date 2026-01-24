#include <iostream>
#include <vector>

using namespace std;

int dy[8]={-1,-1, 0, 1, 1,1, 0, -1};
int dx[8]={0,  1, 1, 1, 0,-1,-1,-1 };
int N,M,K;

struct fireball {
    int m;
    int s;
    int d;
};

vector<vector<vector<fireball>>> fireballMap((51), vector<vector<fireball>>(51));

void move() {
    vector<vector<vector<fireball>>> copyFireballMap((51), vector<vector<fireball>>(51));

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            for (int k=fireballMap[i][j].size()-1; k>=0; k--) {
                auto val = fireballMap[i][j][k];
                int py=(i+(val.s%N)*dy[val.d]+N)%N+1;
                int px=(j+(val.s%N)*dx[val.d]+N)%N+1;
                copyFireballMap[py][px].push_back({val.m, val.s, val.d});
            }
        }
    }

    fireballMap=copyFireballMap;
}

void checkOneUp() {

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (fireballMap[i][j].size()>1) {
                int totalM=0;
                int totalS=0;
                bool isTwo= false;
                bool isNotTwo = false;
                for (int k=0; k<fireballMap[i][j].size(); k++) {
                    auto val= fireballMap[i][j][k];
                    totalS+=val.s;
                    totalM+=val.m;
                    if (val.d%2==0) isTwo=true;
                    else isNotTwo=true;
                }
                int newM=totalM/5;
                int newS=totalS/fireballMap[i][j].size();
                fireballMap[i][j].clear();
                if (newM!=0) {
                    if (isNotTwo&&isTwo) {
                        for (int k=1; k<9; k+=2) {
                            fireballMap[i][j].push_back({newM,newS, k});
                        }
                    }else {
                        for (int k=0; k<8; k+=2) {
                            fireballMap[i][j].push_back({newM,newS, k});
                        }
                    }
                }
            }
        }
    }
}

int output() {
    int total=0;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            for (int k=0; k<fireballMap[i][j].size(); k++) {
                total +=fireballMap[i][j][k].m;
            }
        }
    }

    return total;
}

void input() {
    cin>>N>>M>>K;

    while (M--) {
        int r,c,m,s,d;
        cin>>r>>c>>m>>s>>d;
        fireballMap[r][c].push_back({m,s,d});
    }

    while (K--){
        move();
        checkOneUp();
    }

    int answer=output();
    cout<<answer;
}

int main() {
    input();

    return 0;
}