#include <string>
#include <vector>

using namespace std;

bool isVisited[10];
int maximum=0;
int currentMaximum=0;
vector<int>checking;

void dfs(vector<vector<int>> dungeons, int cnt,int k){
    
    if(cnt==dungeons.size()){
        currentMaximum=0;
        
        for(int j=0; j<checking.size(); j++){
            
            if(dungeons[checking[j]][0]<=k) {
                k-=dungeons[checking[j]][1];
                currentMaximum++;
            }else{
                break;
            }
        }
        if(currentMaximum>maximum) maximum=currentMaximum;
        
        return;
    }
    
    for(int i=0; i<dungeons.size(); i++){
        if(isVisited[i]) continue;
        
        isVisited[i]=true;
        checking.push_back(i);
        dfs(dungeons,cnt+1,k);
        isVisited[i]=false;
        checking.pop_back();
    }
    
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;

    dfs(dungeons,0,k);
    
    answer=maximum;
    
    return answer;
}