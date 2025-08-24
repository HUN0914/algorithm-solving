#include <iostream>
#include <queue>

using namespace std;

const int TOP=0, NORTH=1, EAST=2, WEST=3, SOUTH=4, BOTTOM=5;

int dice[6]={1,2,3,4,5,6};
int new_dice[6]={1,2,3,4,5,6};
int board[20][20];
int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};
int direct=1;
int n,m,k;
int score;

int counting=0;
int location_y=0;
int location_x=0;

void apply(){ for(int i=0;i<6;i++) dice[i]=new_dice[i]; }


void move_right(){
    new_dice[TOP]    = dice[WEST];
    new_dice[BOTTOM] = dice[EAST];
    new_dice[EAST]   = dice[TOP];
    new_dice[WEST]   = dice[BOTTOM];
    new_dice[NORTH]  = dice[NORTH];
    new_dice[SOUTH]  = dice[SOUTH];
    apply();
}

void move_left(){
    new_dice[TOP]    = dice[EAST];
    new_dice[BOTTOM] = dice[WEST];
    new_dice[WEST]   = dice[TOP];
    new_dice[EAST]   = dice[BOTTOM];
    new_dice[NORTH]  = dice[NORTH];
    new_dice[SOUTH]  = dice[SOUTH];
    apply();
}

void move_down(){
    new_dice[TOP]    = dice[NORTH];
    new_dice[BOTTOM] = dice[SOUTH];
    new_dice[SOUTH]  = dice[TOP];
    new_dice[NORTH]  = dice[BOTTOM];
    new_dice[EAST]   = dice[EAST];
    new_dice[WEST]   = dice[WEST];
    apply();
}

void move_up(){
    new_dice[TOP]    = dice[SOUTH];
    new_dice[BOTTOM] = dice[NORTH];
    new_dice[NORTH]  = dice[TOP];
    new_dice[SOUTH]  = dice[BOTTOM];
    new_dice[EAST]   = dice[EAST];
    new_dice[WEST]   = dice[WEST];
    apply();
}

void step(int dir, int &step_y, int &step_x) {
    if (dir==1) { step_y=0; step_x=1;}
    else if (dir==2){ step_y=0; step_x=-1;}
    else if (dir==3){ step_y=1; step_x=0;}
    else { step_y=-1; step_x=0;}
}

void move_direct(int py, int px, int d) {
    int nd=d;
    int sy=0, sx=0;

    step(nd,sy,sx);

    if (py+sy<0||py+sy>=n||px+sx<0||px+sx>=m) {
        if (nd==1) nd=2;
        else if (nd==2) nd=1;
        else if (nd==3) nd=4;
        else nd=3;
        step(nd,sy,sx);
    }

    location_y=py+sy;
    location_x=px+sx;

    if (nd==1) move_right();
    else if (nd==2) move_left();
    else if (nd==3) move_down();
    else move_up();
    direct=nd;

}

void game() {

    move_direct(location_y,location_x,direct);

    int py=location_y;
    int px=location_x;
    bool visited[20][20] ={false};
    int counting=1;
    int b= board[py][px];
    visited[py][px]=true;

    queue<pair<int,int>>q;
    q.push({py,px});

    while (!q.empty()) {
        auto [ny,nx] =q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int y=ny+dy[i];
            int x=nx+dx[i];

            if (y>=n||y<0||x>=m||x<0) continue;
            if (visited[y][x]) continue;
            if (board[y][x]!=b) continue;

            visited[y][x]=true;
            q.push({y,x});
            counting++;
        }
    }
    score+=counting*b;
    int a=dice[BOTTOM];

    if (a>b) {
        if (direct==1) direct=3;
        else if (direct==2) direct=4;
        else if (direct==3) direct=2;
        else direct=1;
    }
    if (a<b) {
        if (direct==1) direct=4;
        else if (direct==4) direct=2;
        else if (direct==2) direct=3;
        else direct=1;
    }
}

int main() {

    cin>>n>>m>>k;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>board[i][j];
        }
    }

    for (int i=0; i<k; i++) game();

    cout<<score<<"\n";

    return 0;
}