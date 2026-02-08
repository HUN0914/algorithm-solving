#include<vector>
#include<queue>
using namespace std;

bool isVisited[101][101];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

struct location{
    int y;
    int x;
    int cnt;
};

int game(vector<vector<int>> maps){
    int result=-1;
    int n=maps.size();
    int m=maps[0].size();
        
    queue<location>q;
    
    q.push({0,0,1});
    isVisited[0][0]=true;
    
    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int cnt=q.front().cnt;
        q.pop();
        if(y==n-1&&x==m-1){ return cnt; }
        
        for(int i=0; i<4; i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            
            if(ny<0||ny>=n||nx<0||nx>=m) continue;
            if(maps[ny][nx]==0||isVisited[ny][nx]==true) continue;
            
            isVisited[ny][nx]=true;
            q.push({ny,nx,cnt+1});
        }
    }
    
    return result;
}

int solution(vector<vector<int> > maps)
{
    int answer = game(maps);
    return answer;
}