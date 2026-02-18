#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct horse {
    int locationX;
    int locationY;
    int dir;
};
// 0 : 오 1 : 왼 2 : 위 3: 아
int dy[4]={0,0,-1,1};;
int dx[4]={1,-1,0,0};
int n,k;
vector<vector<vector<int>>> horseMap(13, vector<vector<int>> (13));
vector<horse>horses (13); //1 index
int map[13][13];

void choiceWhite(int curr, int ny, int nx, int y, int x) {
    if (horseMap[y][x].size()>1) {
        int currLocation=-1;
        for (int j=0; j<horseMap[y][x].size(); j++) {
            if (horseMap[y][x][j]==curr) currLocation=j;
        }
        for (int j= currLocation; j<horseMap[y][x].size(); j++) {
            horses[horseMap[y][x][j]].locationX=nx;
            horses[horseMap[y][x][j]].locationY=ny;
            horseMap[ny][nx].push_back(horseMap[y][x][j]);
        }
        int size=horseMap[y][x].size();
        for (int j= currLocation; j<size; j++) { horseMap[y][x].pop_back(); }

    }else {
        horses[curr].locationX=nx;
        horses[curr].locationY=ny;
        horseMap[ny][nx].push_back(curr);
        horseMap[y][x].pop_back();
    }
}

void choiceRed(int curr, int ny, int nx, int y, int x) {
    stack<int>imsiHorses;
    int currLocation=-1;
    for (int j=0; j<horseMap[y][x].size(); j++) {
        if (horseMap[y][x][j]==curr) currLocation=j;
    }
    for (int j=currLocation; j<horseMap[y][x].size(); j++){imsiHorses.push(horseMap[y][x][j]);}

    int size=horseMap[y][x].size();
    for (int j= currLocation; j<size; j++) { horseMap[y][x].pop_back(); }

    while (!imsiHorses.empty()) {
        int val = imsiHorses.top();
        imsiHorses.pop();

        horses[val].locationY=ny;
        horses[val].locationX=nx;
        horseMap[ny][nx].push_back(val);
    }
}

void choiceBlue(int curr, int y, int x) {
    if (horses[curr].dir==0){ horses[curr].dir=1; }
    else if (horses[curr].dir==1){ horses[curr].dir=0; }
    else if (horses[curr].dir==2){ horses[curr].dir=3; }
    else if (horses[curr].dir==3){ horses[curr].dir=2; }
    int nx=x+dx[horses[curr].dir];
    int ny=y+dy[horses[curr].dir];

    if (nx<0||nx>=n||ny<0||ny>=n||map[ny][nx]==2) return;
    if (map[ny][nx]==1) { choiceRed(curr,ny,nx,y,x); }
    else if (map[ny][nx]==0) { choiceWhite(curr,ny,nx,y,x); }
}

int game() {
    int cnt=0;
    while (cnt<1000) {

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++) if (horseMap[i][j].size()>=4) return cnt;

        for (int i=1; i<=k; i++) {
            int y= horses[i].locationY;
            int x= horses[i].locationX;
            int ny=y+dy[horses[i].dir];
            int nx=x+dx[horses[i].dir];

            if (horseMap[y][x][0]!=i) continue;

            if (ny<0||ny>=n||nx<0||nx>=n) choiceBlue(i,y,x);
            else if (map[ny][nx]==0) { choiceWhite(i,ny,nx,y,x); }
            else if (map[ny][nx]==1) { choiceRed(i,ny,nx,y,x); }
            else if (map[ny][nx]==2) { choiceBlue(i,y,x);}

        }
        cnt++;
    }

    return -1;
}

void input() {
    cin>>n>>k;
    //0 : 흰 1 : 빨강 2: 파랑
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) cin>>map[i][j];

    for (int i=1; i<=k; i++) {
        int row,col,dir;
        cin>>row>>col>>dir;
        row--;
        col--;
        horses[i].locationY=row;
        horses[i].locationX=col;
        horses[i].dir=dir-1;
        horseMap[row][col].push_back(i);
    }
}

int main() {
    input();
    cout<<game();
    return 0;
}
