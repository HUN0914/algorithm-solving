#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
map<string, int> names;
int boards[51][51];
int people[51];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    for(int i=0; i<friends.size(); i++){
        string name=friends[i];
        names[name]=i;
    }
    
    for(int i=0;i<gifts.size();i++){
        string target=gifts[i];
        int find_space=target.find(' ');
        string from_name= target.substr(0,find_space);
        string to_name=target.substr(find_space+1);
        
        int fIdx= names[from_name];
        int tIdx= names[to_name];
        
        people[fIdx]++;
        people[tIdx]--;
        boards[fIdx][tIdx]++;
    }
    
    for(int i=0; i<friends.size();i++){
        int ret=0;
        int maximum=-1;
        
        for(int j=0; j<friends.size(); j++){
            if(i==j) continue;
            
            if(boards[i][j]>boards[j][i]){
                ret++;
            }
            if(boards[i][j]== boards[j][i]||(boards[i][j]==0&&boards[j][i]==0)){
                if(people[i]>people[j]){
                    ret++;
                }
            }
        answer= max(answer, ret);
    }
    }
    
    return answer;
}