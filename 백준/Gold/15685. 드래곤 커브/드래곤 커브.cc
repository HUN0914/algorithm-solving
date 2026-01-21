#include <iostream>
#include <vector>

using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int py[3]={0,1,1};
int px[3]={1,1,0};

vector<int>directions;
bool isVisited[101][101];
int n;

void dragon(int x, int y) {

    int nx=x;
    int ny=y;
    for (int i=0; i<directions.size(); i++) {

        nx+=dx[directions[i]];
        ny+=dy[directions[i]];
       isVisited[nx][ny]=true;;
    }

}

void input() {
    cin>>n;

    for (int i=0; i<n; i++) {
        int x,y,d,g;
        cin>>x>>y>>d>>g;
        directions.clear();
        isVisited[x][y]=true;
        directions.push_back(d);
        for (int j=0; j<g; j++) {
            for (int k=directions.size()-1; k>=0; k--) {
                directions.push_back((directions[k]+1)%4);
            }
        }
        dragon(x,y);
    }
}

void output() {

    int total=0;

    for (int i=0; i<=100; i++) {
        for (int j=0; j<=100; j++) {
            if (isVisited[i][j]) {
                int squareCount=0;
                for (int k=0; k<3; k++) {
                    if (i+px[k]<0||i+px[k]>100||j+py[k]<0||j+py[k]>100) continue;
                    if (isVisited[i+px[k]][j+py[k]]) squareCount++;
                }
                if (squareCount==3) total++;
            }
        }
    }
    cout<<total;
}

int main() {
    input();
    output();
}
