#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0}; //오 왼 위 아

struct horse {
    int locationY;
    int locationX;
    int dir;
};

vector<horse> horses;
vector<vector<vector<int>>> horseNumber(12, vector<vector<int>>(12));

int map[12][12];

int n,k;

void move(int curr, int ny, int nx, int y, int x) {
    int curLocation=-1;
    for (int i=0; i<horseNumber[y][x].size(); i++) {
        if (horseNumber[y][x][i]==curr) {
            curLocation=i;
            break;
        }
    }

    for (int i=curLocation; i<horseNumber[y][x].size(); i++) {
        horseNumber[ny][nx].push_back({horseNumber[y][x][i]});
        horses[horseNumber[y][x][i]].locationY=ny;
        horses[horseNumber[y][x][i]].locationX=nx;
    }

    int size= horseNumber[y][x].size();
    for (int i=curLocation; i<size; i++) horseNumber[y][x].pop_back();
}

void checkRed(int curr, int ny, int nx, int y, int x) {
    int curLocation=-1;
    for (int i=0; i<horseNumber[y][x].size(); i++) {
        if (horseNumber[y][x][i]==curr) {
            curLocation=i;
            break;
        }
    }

    stack<int> s;

    for (int i=curLocation; i<horseNumber[y][x].size(); i++) { s.push(horseNumber[y][x][i]); }

    while (!s.empty()) {
        int val=s.top();
        s.pop();
        horseNumber[ny][nx].push_back(val);
        horses[val].locationY=ny;
        horses[val].locationX=nx;
    }

    int size= horseNumber[y][x].size();
    for (int i=curLocation; i<size; i++) horseNumber[y][x].pop_back();
}

void checkBlue(int curr, int y, int x) {

    if (horses[curr].dir==0) horses[curr].dir=1;
    else if (horses[curr].dir==1) horses[curr].dir=0;
    else if (horses[curr].dir==2) horses[curr].dir=3;
    else if (horses[curr].dir==3) horses[curr].dir=2;

    int ny=y+dy[horses[curr].dir];
    int nx=x+dx[horses[curr].dir];

    if (ny<0||ny>=n||nx<0||nx>=n||map[ny][nx]==2) return;

    if (map[ny][nx]==1) { checkRed(curr,ny,nx,y,x); }
    else if (map[ny][nx]==0) { move(curr,ny,nx,y,x); }

}

int game() {

    int cnt=1;
    while (cnt<1000) {

        for (int i=0; i<horses.size(); i++) {
            int y=horses[i].locationY;
            int x=horses[i].locationX;
            int dir=horses[i].dir;

            int ny=y+dy[dir];
            int nx=x+dx[dir];

            if (ny<0||ny>=n||nx<0||nx>=n||map[ny][nx]==2) checkBlue(i, y, x);
            else if (map[ny][nx]==1) checkRed(i, ny, nx, y,x);
            else if (map[ny][nx]==0) move(i,ny,nx,y,x);

            if (horseNumber[horses[i].locationY][horses[i].locationX].size()>=4) return cnt;
        }
        cnt++;
    }

    return -1;
}

void input() {
    cin>>n>>k;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) cin>>map[i][j];

    for (int i=0; i<k; i++) {
        int x,y,dir;
        cin>>y>>x>>dir;
        y--;
        x--;
        dir--;
        horses.push_back({y,x,dir});
        horseNumber[y][x].push_back(i);
    }
}

int main() {

    input();
    cout<<game();

    return 0;
}