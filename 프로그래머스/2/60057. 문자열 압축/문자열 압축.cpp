#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    for(int i=1; i<=s.size()/2; i++){
        
        string tempString="";
        string value=s.substr(0,i);
        int cnt=1;
        for(int j=i; j<s.size(); j+=i){
            if(s.substr(j,i)==value){
                cnt++;
            }else{
                if(cnt>1) tempString+=to_string(cnt);
                tempString+=value;
                value=s.substr(j,i);
                cnt=1;
            }
        }
        if(cnt>1){
            tempString+=to_string(cnt);
        }
        tempString+=value;
        
        if(answer>tempString.size()) answer=tempString.size();
        
    }
    
    return answer;
}