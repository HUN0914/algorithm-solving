#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>>virus;


int n,m;

int board[51][51];
bool virus_visited[11];
int init_zero_count=0;
vector<pair<int,int>>result_virus;
queue<pair<int,int>>q;
int min_time=987654321;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

void bfs() {
    bool visited[51][51]={false};
    int time[51][51]={0};
    queue<pair<int,int>>q;
    int zero_count=init_zero_count;
    int max_time=0;

    for (int i=0; i<result_virus.size();i++) {
        q.push(result_virus[i]);
        visited[result_virus[i].first][result_virus[i].second]=true;
    }

    while (!q.empty()) {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();

            for (int i=0; i<4; i++) {
                int ny=y+dy[i];
                int nx=x+dx[i];
                if (ny>=0&&ny<n&&nx>=0&&nx<n&&board[ny][nx]!=1&&!visited[ny][nx]) {
                    visited[ny][nx]=true;
                    time[ny][nx]=time[y][x]+1;
                    q.push({ny,nx});

                    if (board[ny][nx]==0) {
                        zero_count--;
                        max_time=max(max_time,time[ny][nx]);
                    }

            }
        }

    }

    if (zero_count==0) {
        min_time=min(max_time,min_time);
    }


}

void dfs(int depth, int start) {
    if (depth==m) {
        bfs();
        return;
    }

    for (int i=start; i<virus.size(); i++) {
        if (!virus_visited[i]) {
            result_virus.push_back(virus[i]);
            dfs(depth+1,i+1);
            result_virus.pop_back();
        }
    }

}

int main(void) {


    cin>>n>>m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>board[i][j];
            if (board[i][j]==2) {
                virus.push_back(make_pair(i,j));
            }
            if (board[i][j]==0) {
                init_zero_count++;
            }
        }
    }

    dfs(0,0);

    if (min_time == 987654321) cout << -1 << '\n';
    else cout << min_time << '\n';

    return 0;
}