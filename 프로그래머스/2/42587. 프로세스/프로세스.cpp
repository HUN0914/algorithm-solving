#include <string>
#include <vector>
#include <queue>

using namespace std;

int game(vector<int> priorities, int location){
    
    vector<pair<int,int>>currProperties;
    
    for(int i=0; i<priorities.size(); i++){ currProperties.push_back({i,priorities[i]});}
    
    int answerItem=priorities[location];
    
    int cnt=1;
    
    while(true){
        queue<pair<int,int>> q;
        int maximumLocation=-1;
        int maximum=-1;
        
        for(int i=0; i<currProperties.size(); i++)
            if(currProperties[i].second>maximum){
                maximumLocation=i;
                maximum=currProperties[i].second;
            }
        if(currProperties[maximumLocation].first==location) break;
    
        for(int i=maximumLocation+1; i<currProperties.size(); i++){ 
            int curLocation=currProperties[i].first;
            int curVal=currProperties[i].second;
            q.push({curLocation,curVal});
        }    
        
        for(int i=0; i<maximumLocation; i++){ 
            int curLocation=currProperties[i].first;
            int curVal=currProperties[i].second;
            q.push({curLocation,curVal});
        }
    
        currProperties.clear();
        while(!q.empty()){
            
            int valLocation=q.front().first;
            int val=q.front().second;
            currProperties.push_back({valLocation,val});
            q.pop();
        }
        cnt++;
    }
    
   return cnt; 
}

int solution(vector<int> priorities, int location) {
    int answer = game(priorities, location);
    
    return answer;
}