#include <iostream>
#include <vector>

using namespace std;

int n;
int map[22][22];
int checkStudentLove[22][22];
int emptyMap[22][22];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<vector<int>> arr(4001, vector<int>(4));

void checkLove(int studentNumber) {

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            checkStudentLove[i][j]=0;
            emptyMap[i][j]=0;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (map[i][j] != 0) continue;
            for (int k=0; k<4; k++) {
                if (i+dy[k]<0||i+dy[k]>=n||j+dx[k]<0||j+dx[k]>=n) continue;

                if (map[i+dy[k]][j+dx[k]]==0) emptyMap[i][j]++;

                for (int m : arr[studentNumber]) {
                    if (map[i+dy[k]][j+dx[k]]==m) checkStudentLove[i][j]++;
                }
            }
        }
    }
}

void decideLocation(int studentNumber) {
    int maximumStudent=-1;
    int maximumEmptyCount=-1;
    int row=0;
    int col=0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {

            if (map[i][j]!=0) continue;
            if (maximumStudent<checkStudentLove[i][j]) {
                col=i;
                row=j;
                maximumStudent=checkStudentLove[i][j];
                maximumEmptyCount=emptyMap[i][j];
            }
            else if (maximumStudent==checkStudentLove[i][j]) {
                if (maximumEmptyCount<emptyMap[i][j]) {
                    col=i;
                    row=j;
                    maximumEmptyCount=emptyMap[i][j];
                }else if (maximumEmptyCount==emptyMap[i][j]) {
                    if (col>i) {
                        col=i;
                        row=j;
                    }else if (col==i) {
                        if (row>j) {
                            row=j;
                        }
                    }
                }
            }
        }
    }
    map[col][row]=studentNumber;
}

void game(int studentNumber) {
    checkLove(studentNumber);
    decideLocation(studentNumber);
}

int result() {
    int total=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                int friendlyCount=0;
                int initFriend=map[i][j];

                for (int k=0; k<4; k++) {
                    int ny=i+dy[k];
                    int nx=j+dx[k];
                    if (ny>=n||ny<0||nx>=n||nx<0) continue;
                    for (int m=0; m<arr[initFriend].size(); m++){
                        if (map[ny][nx]==arr[initFriend][m]) friendlyCount++;
                    }
                }
                if (friendlyCount==1) total+=1;
                if (friendlyCount==2) total+=10;
                if (friendlyCount==3) total+=100;
                if (friendlyCount==4) total+=1000;
            }
        }
    return total;
}

void input() {
    cin>>n;

    for (int i=0; i<n*n; i++) {
        int studentNumber;
        cin>>studentNumber;
        for (int j=0; j<4; j++) {
            cin>>arr[studentNumber][j];
        }
        game(studentNumber);
    }
    int total=result();
    cout<<total;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    input();

    return 0;
}