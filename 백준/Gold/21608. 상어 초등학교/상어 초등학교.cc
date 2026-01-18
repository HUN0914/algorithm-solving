#include <iostream>
#include <vector>

using namespace std;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

int board[21][21];
int n;
vector<vector<int>>studentsList(4001);

void choiceLocation(int studentOne) {
    int nearMaxFriends=-1;
    int nearMaxEmpty=-1;
    int decideY=0;
    int decideX=0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (board[i][j]!=0) continue;
            int nearFriend=0;
            int nearEmpty=0;
            for (int k=0; k<4; k++) {
                int ny=i+dy[k];
                int nx=j+dx[k];
                if (ny>=n||ny<0||nx>=n||nx<0) continue;
                for (auto & a: studentsList[studentOne]){
                    if (a==board[ny][nx]) nearFriend++;
                }
                if (board[ny][nx]==0) nearEmpty++;
            }
            if (nearFriend>nearMaxFriends) {
                decideY=i;
                decideX=j;
                nearMaxFriends=nearFriend;
                nearMaxEmpty=nearEmpty;
            }else if (nearFriend==nearMaxFriends) {
                if (nearEmpty>nearMaxEmpty) {
                    decideY=i;
                    decideX=j;
                    nearMaxEmpty=nearEmpty;
                }else if (nearEmpty==nearMaxEmpty) {
                    if (decideY>i) {
                        decideY=i;
                        decideX=j;
                    }else if (decideY==i) {
                        if (decideX>j) {
                            decideX=j;
                        }
                    }
                }
            }
        }
    }

    board[decideY][decideX]=studentOne;
}

void calculateScore() {
    int score=0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int studentNumber=board[i][j];
            int likeCount=0;
            for (int a=0; a<4; a++) {
                int ny=i+dy[a];
                int nx=j+dx[a];
                if (ny>=n||ny<0||nx>=n||nx<0) continue;
                for (auto & b : studentsList[studentNumber]){
                    if (b==board[ny][nx]) likeCount++;
                }
            }
            if (likeCount==0) score+=0;
            if (likeCount==1) score+=1;
            if (likeCount==2) score+=10;
            if (likeCount==3) score+=100;
            if (likeCount==4) score+=1000;
        }
    }
    cout<<score;
}

void input() {
    cin>>n;

    for (int i=1; i<=n*n; i++) {
        int studentOne, one,two,three,four;
        cin>>studentOne>>one>>two>>three>>four;
        studentsList[studentOne].push_back(one);
        studentsList[studentOne].push_back(two);
        studentsList[studentOne].push_back(three);
        studentsList[studentOne].push_back(four);
        choiceLocation(studentOne);
    }
}

void game() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            board[i][j]=0;
        }
    }
    input();
    calculateScore();
}

int main() {
    game();
}