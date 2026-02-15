#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int r,c,k;
int map[101][101];
int numberCnt[101];
int row=3;
int col=3;

void calRow() { //세로 길때

    vector<int>size;
    for (int i=1; i<=row; i++) {
        vector<pair<int,int>>v;
        memset(numberCnt, 0, sizeof(numberCnt));

        for (int j=1; j<=col; j++) numberCnt[map[i][j]]++;

        for (int j=1; j<=100; j++) {
            if (numberCnt[j]==0) continue;
            v.push_back({numberCnt[j],j});
        }
        sort(v.begin(), v.end());

        for (int j=1; j<=col; j++) map[i][j]=0;

        int idx=1;

        for (int j=0; j<v.size(); j++) {
            map[i][idx++]=v[j].second;
            map[i][idx++]=v[j].first;
        }
        idx--;
        size.push_back(idx);
    }
    sort(size.begin(),size.end());
    col=size.back();
}

void calCol() {

    vector<int> size;
    for (int i=1; i<=col; i++) {
        vector<pair<int,int>> v;
        memset(numberCnt, 0, sizeof(numberCnt));

        for (int j=1; j<=row; j++) { numberCnt[map[j][i]]++; }

        for (int j=1; j<=100; j++) {
            if (numberCnt[j]==0) continue;
            v.push_back({numberCnt[j],j});
        }

        sort(v.begin(), v.end());
        for (int j=1; j<=row; j++) map[j][i]=0;

        int idx=1;
        for (int j=0; j<v.size(); j++) {
            map[idx++][i]=v[j].second;
            map[idx++][i]=v[j].first;
        }
        idx--;
        size.push_back(idx);
    }
    sort(size.begin(),size.end());
    row=size.back();
}

int find() {
    int time=0;

    while (true) {
        if (time>100) break;
        if (map[r][c]==k) return time;
        vector<int> size;
        if (row>=col) calRow();
        else calCol();
        time++;
    }

    return -1;
}

void input() {
    cin>>r>>c>>k;
    for (int i=1; i<=3; i++)
        for (int j=1; j<=3; j++) cin>>map[i][j];
}

void game() {
    input();
    int answer=find();
    cout<<answer;
}

int main() {
    game();
}