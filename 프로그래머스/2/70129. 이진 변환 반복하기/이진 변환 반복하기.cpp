#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    string newString;
    string initString=s;
    int cnt=0;
    int cntZero=0;
    
    while(1){
        if(initString.size()==1) break;
        
        for(int i=0; i<initString.size(); i++){
            if(initString[i]=='0'){
                cntZero++;
                continue;
            }
            newString+=initString[i];
        }
        int newSize=newString.size();
        
        initString="";
        newString="";
        
        while(newSize>0){
            
            if(newSize%2==0){
                initString+="0";
            }else{
                initString+="1";
            }
            newSize/=2;
        }
        
        cnt++;
        
    }
    
    answer.push_back(cnt);
    answer.push_back(cntZero);
    
    return answer;
}