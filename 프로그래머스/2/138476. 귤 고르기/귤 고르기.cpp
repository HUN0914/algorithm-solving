#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int,int> m;
    vector<vector<int>> numbering;
    
    for(int i=0; i<tangerine.size(); i++){
        m[tangerine[i]]++;
    }
    
    for(auto& t : m){
        numbering.push_back({t.second,t.first});
    }
    
    sort(numbering.begin(),numbering.end());
    
    int sum=0;
    for(int i=numbering.size()-1; i>=0; i--){
        sum+=numbering[i][0];
        answer++;
        if(sum>=k) break;
        
    }
    
    return answer;
}