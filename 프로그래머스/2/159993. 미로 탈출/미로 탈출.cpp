#include <string>
#include <vector>
#include <queue>

using namespace std;
/*
레버 먼저 찾는 BFS 돌리고 
그떄의 bfs 값 반환받고

레버에서 다시 출구까지 BFS 돌리기

이 2가지 케이스 모두 못나가면 -1 반환
*/
int start_x;
int start_y;
int l_x;
int l_y;
char lever_map[101][101];
char exit_map[101][101];
bool visited_lever[101][101];
bool visited_exit[101][101];
int nx[4]={-1,1,0,0};
int ny[4]={0,0,-1,1};
vector<pair<int,int>> lever_location;
struct Noding{
    int y,x,dist;
};

int find_bfs(int sy, int sx, int y_size, int x_size){
    queue<Noding> q;
    q.push({sy,sx,0});
    visited_lever[sy][sx]=true;
    
    while(!q.empty()){
        Noding cur = q.front();
        q.pop();
        int px=cur.x;
        int py=cur.y;
        
        if(lever_map[py][px]=='L'){
            py=l_y;
            px=l_x;
            return cur.dist;
        }
        
        for(int i=0; i<4; i++){
            int dx=px+nx[i];
            int dy=py+ny[i];
            
            if(visited_lever[dy][dx]==true) continue;
            
            if(dx<0||dx>=x_size||dy<0||dy>=y_size||lever_map[dy][dx]=='X') continue;
            
            visited_lever[dy][dx]=true;
            q.push({dy,dx,cur.dist+1});
        }
        
    }
    
    return -1;
}

int find_exit(int l_y, int l_x ,int y_size, int x_size){
    queue<Noding> q;
    q.push({l_y,l_x,0});
    
    visited_exit[l_y][l_x]=true;
    
    while(!q.empty()){
        
        Noding cur = q.front();
        q.pop();
        int px=cur.x;
        int py=cur.y;
        
        if(exit_map[py][px]=='E'){
            return cur.dist;
        }
        for(int i=0;i<4;i++){
            int dy=py+ny[i];
            int dx=px+nx[i];
            
            if(dy<0||dy>=y_size||dx<0||dx>=x_size||exit_map[dy][dx]=='X'||visited_exit[dy][dx]==true) continue;
            
            q.push({dy,dx,cur.dist+1});
            visited_exit[dy][dx]=true;
            
        }
    }
    return -1;
}


int solution(vector<string> maps) {
    int answer = 0;
    
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[i].size();j++){
            if(maps[i][j]=='S'){
                start_y=i;
                start_x=j;
            }
            if(maps[i][j]=='L'){
                l_y=i;
                l_x=j;
            }
            
            lever_map[i][j]=maps[i][j];
            exit_map[i][j]=maps[i][j];
        }        
    }
    
    int lever_cnt=find_bfs(start_y, start_x, maps.size(), maps[0].size());
    
    if(lever_cnt==-1) {
        return -1;
        
    }else {
        int exit_cnt=find_exit(l_y, l_x, maps.size(), maps[0].size());
        if(exit_cnt==-1) return -1;
        answer=lever_cnt+exit_cnt;
    }
    
    
    return answer;
}