#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct tree {
    int age;
    bool isDie;
};

vector<vector<deque<tree>>> treesMap(11, vector<deque<tree>>(11));
int map[11][11];
int feed[11][11];

int dy[8]={-1,-1,-1,0,1,1,1,0};
int dx[8]={-1,0,1,1,1,0,-1,-1};

bool operate(tree& treeA, tree& treeB) {
    return treeA.age>treeB.age;
}

int n,m,k;

void spring() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!treesMap[i][j].empty()) {
                for (int c=treesMap[i][j].size()-1; c>=0; c--) {
                    if (treesMap[i][j][c].age<=map[i][j]) {
                        map[i][j]-=treesMap[i][j][c].age;
                        treesMap[i][j][c].age++;
                    }else { treesMap[i][j][c].isDie=true; }
                }
            }
        }
    }
}

void summer() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int point=-1;
            if (!treesMap[i][j].empty()) {
                for (int c=treesMap[i][j].size()-1; c>=0; c--) {
                    if (treesMap[i][j][c].isDie) {
                        point=c;
                        break;
                    }
                }
                for (int c=0; c<=point; c++) map[i][j]+=treesMap[i][j][c].age/2;
                for (int c=0; c<=point; c++) treesMap[i][j].pop_front();
            }
        }
    }
}

void fall() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int c=0; c<treesMap[i][j].size(); c++) {
                if (treesMap[i][j][c].age%5==0) {
                    for (int a=0; a<8; a++) {
                        int ny=i+dy[a];
                        int nx=j+dx[a];
                        if (ny<0||ny>=n||nx<0||nx>=n) continue;
                        treesMap[ny][nx].push_back({1,false});
                    }
                }
            }
        }
    }
}

void winter() {
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) map[i][j]+=feed[i][j];
}

void game() {
    int total=0;

    while (k--) {
        spring();
        summer();
        fall();
        winter();
    }

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) total += treesMap[i][j].size();

    cout<<total;
}

void init() {
    cin>>n>>m>>k;

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) cin>>feed[i][j];

    for (int i=0; i<m; i++) {
        int x,y,z;
        cin>>x>>y>>z;
        treesMap[x-1][y-1].push_back({z,false});
    }

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) map[i][j]=5;

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            sort(treesMap[i][j].begin(), treesMap[i][j].end(), operate);

}

int main() {
    init();
    game();
}