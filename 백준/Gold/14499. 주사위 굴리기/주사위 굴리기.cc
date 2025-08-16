#include <iostream>
#include <vector>

using namespace std;

int board[21][21];
vector<int> order;
int dice[7];
int new_dice[7];
bool isTrue_move;
int N,M;

void paste_board(int ny,int nx){

    if (board[ny][nx]==0) {
        board[ny][nx]=new_dice[6];
    }else {
        new_dice[6]=board[ny][nx];
        board[ny][nx]=0;
    }
}

void move_North(int ny,int nx) {
    new_dice[3]=dice[3];
    new_dice[4]=dice[4];
    new_dice[1]=dice[5];
    new_dice[2]=dice[1];
    new_dice[5]=dice[6];
    new_dice[6]=dice[2];

    paste_board(ny,nx);
}

void move_South(int ny,int nx) {
    new_dice[3]=dice[3];
    new_dice[4]=dice[4];
    new_dice[1]=dice[2];
    new_dice[2]=dice[6];
    new_dice[5]=dice[1];
    new_dice[6]=dice[5];

    paste_board(ny,nx);
}

void move_East(int ny,int nx) {
    new_dice[1]=dice[4];
    new_dice[2]=dice[2];
    new_dice[3]=dice[1];
    new_dice[4]=dice[6];
    new_dice[5]=dice[5];
    new_dice[6]=dice[3];

    paste_board(ny,nx);
}

void move_West(int ny,int nx) {
    new_dice[2]=dice[2];
    new_dice[5]=dice[5];
    new_dice[1]=dice[3];
    new_dice[3]=dice[6];
    new_dice[4]=dice[1];
    new_dice[6]=dice[4];

    paste_board(ny,nx);
}

void game(int x, int y) {
    int ny=x;
    int nx=y;

    for (int i=0; i<order.size(); i++) {
        isTrue_move=false;

        if (order[i]==1&&nx+1<M) {
            nx++;
            move_East(ny,nx);
            isTrue_move=true;
        }
        if (order[i]==2&&nx-1>=0) {
            nx--;
            move_West(ny,nx);
            isTrue_move=true;
        }
        if (order[i]==3&&ny-1>=0) {
            ny--;
            move_North(ny,nx);
            isTrue_move=true;
        }
        if (order[i]==4&&ny+1<N) {
            ny++;
            move_South(ny,nx);
            isTrue_move=true;
        }

        if (isTrue_move) {
            for (int val=1; val<=6; val++) dice[val]=new_dice[val];
            cout<<dice[1]<<"\n";
        }
    }
}

int main() {

    int x,y,K;

    cin>>N>>M>>x>>y>>K;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin>>board[i][j];
        }
    }

    int order_number;
    for (int i=0; i<K; i++) {
        cin>>order_number;
        order.push_back(order_number);
    }

    game(x,y);

    return 0;
}