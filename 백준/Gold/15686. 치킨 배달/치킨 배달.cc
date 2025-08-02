#include <iostream>
#include <queue>
#include <math.h>


using namespace std;

bool board_visited[51][51];
int board[51][51];
vector<pair<int,int>> chickenhome_location;
vector<pair<int,int>> combination;

int one_counting=0;
vector<pair<int,int>>one_count_location;

int n;
int m;
int maximum=0;
int minimum=987654321;

int global_min = 987654321;

int ny[4]={-1,1,0,0};
int nx[4]={0,0,-1,1};

void bfs(vector<pair<int,int>> comb, int one_count[]) {

    queue<pair<int,int>>q;
    for (int i=0; i<51; i++) {
        for (int j=0; j<51; j++) {
            board_visited[i][j]=false;
        }
    }

   for (int i=0; i<comb.size(); i++) {
    q.push(comb[i]);
   }

    while (!q.empty()) {

        int dy=q.front().first;
        int dx=q.front().second;
        q.pop();

        for (int i=0; i<one_count_location.size(); i++) {
            one_count[i]=min(one_count[i],abs(one_count_location[i].first-dy)+abs(one_count_location[i].second-dx));
        }

    }

}


void dfs(int index, int selected, int m) {
    if (selected == m) {
        int temp[1000];
        for (int i = 0; i < one_counting; i++) temp[i] = 987654321;
        bfs(combination, temp);

        int sum = 0;
        for (int i = 0; i < one_counting; i++) sum += temp[i];

        global_min = min(global_min, sum);
        return;
    }

    for (int i = index; i < chickenhome_location.size(); i++) {
        combination.push_back(chickenhome_location[i]);
        dfs(i + 1, selected + 1, m);
        combination.pop_back();
    }
}

int main(void) {

    cin>>n>>m;

    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>board[i][j];
            if (board[i][j]==2) {
                chickenhome_location.push_back({i,j});
            }
            if (board[i][j]==1) {
                one_counting++;
                one_count_location.push_back({i,j});
            }
        }
    }

    int dist_home[51];
    for (int i = 0; i < one_counting; i++) {
        dist_home[i] = 987654321;
    }


    dfs(0, 0, m);
    cout << global_min << '\n';


    return 0;
}

/*
 *
 *m개씩 담아놓고 그걸 돌렸을 때 거리의 최소
 *
 */