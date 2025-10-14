#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isGreater(const vector<int>& v1, const vector<int>&v2){
    return v1[1]>v2[1];
}

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int,int>m;
    
    string number="";    
    
    for(int i=0; i<s.size()-1; i++){
        if(s[i]=='{') continue;
        
        
        if(s[i]=='}'){
            int value=stoi(number);
            m[value]++;
            number="";
        }else if(s[i]==',')
        {
            if(s[i+1]=='{'){
                continue;
            }else{
                int value=stoi(number);
                m[value]++;
                number="";
            }
        }else{
            number+=s[i];
        }
        
    }
    
    vector<vector<int>>v;
    
    for(auto &p : m){
        v.push_back({p.first, p.second});
    }
    
    sort(v.begin(), v.end(), isGreater);
    
    for(auto & t : v){
        answer.push_back(t[0]);
    }
    
    return answer;
}
