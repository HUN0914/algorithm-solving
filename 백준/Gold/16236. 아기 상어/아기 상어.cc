#include <iostream>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;

int dy[4]={-1,0,0,1};
int dx[4]={0,-1,1,0};

struct Shark {
    int y;
    int x;
    int size;
    int eat_size;

};
Shark shark{0,0,2,0};

int n;
int boards[20][20];
bool possible_move;

int live_fish;
int timer=0;

int bfs() {
    queue<tuple<int,int,int>>q;
    bool visited[20][20];
    int dist[20][20];

    for (auto & i : visited) {
        for (bool & j : i) {
            j=false;
        }
    }

    for (auto & i : dist) {
        for (int & j : i) {
            j=0;
        }
    }

    int best=987654321;
    int fy=-1;
    int fx=-1;

    q.push({shark.y,shark.x,0});
    visited[shark.y][shark.x]=true;

    while (!q.empty()) {
        auto [ny, nx, distance] = q.front();
        q.pop();
        if (distance>best) break;

        for (int i=0; i<4; i++) {
            int y=ny+dy[i];
            int x=nx+dx[i];

            if (y>=n||y<0||x>=n||x<0) continue;
            if (boards[y][x]>shark.size) continue;
            if (visited[y][x]==true) continue;

            int d=distance+1;

            if (boards[y][x]<shark.size&& boards[y][x]!=0) {
                if (d < best|| (d==best&&(y<fy||(y==fy&&x<fx)))){
                    best=d;
                    fy=y;
                    fx=x;
                };
            }
            visited[y][x]=true;
            q.push({y,x,d});
        }
    }

    if (fy == -1) return 0;

    boards[fy][fx]=0;
    shark.y=fy;
    shark.x=fx;
    shark.eat_size++;
    if (shark.size==shark.eat_size) {
        shark.size++;
        shark.eat_size=0;
    }
    return best;
}

int main() {

    cin>>n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>boards[i][j];
            if (boards[i][j]==9) {
                boards[i][j]=0;
                shark.y=i;
                shark.x=j;
            }
        }
    }

    int total_time=0;
    while (true) {
        int t=bfs();
        if (t==0) break;
        total_time+=t;
    }

    cout<<total_time<<"\n";

    return 0;
}