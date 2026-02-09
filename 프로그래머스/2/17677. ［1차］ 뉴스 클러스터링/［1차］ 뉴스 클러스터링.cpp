#include <string>
#include <vector>
using namespace std;

string newStr1;
string newStr2;
vector<string> s1;
vector<string> s2;
bool s1Visited[1001];
bool s2Visited[1001];

int calSet(vector<string> s1, vector<string> s2){
    if(s1.size()==0&&s2.size()==0) return 65536;
    
    double minResult=0;
    double maxResult=0;
    
    for(int i=0; i<s1.size(); i++){
        for(int j=0; j<s2.size(); j++){
            if(s1[i]==s2[j]&&s1Visited[i]==false&&s2Visited[j]==false){
                s1Visited[i]=true;
                s2Visited[j]=true;
                minResult+=1;
                break;
            }
        }    
    }
    maxResult=minResult;
    
    for(int i=0; i<s1.size(); i++){ if(!s1Visited[i]) maxResult+=1; }
    for(int i=0; i<s2.size(); i++){ if(!s2Visited[i]) maxResult+=1; }
    
    return minResult/maxResult*65536;
}

void createVector(string newStr1, string newStr2){
    for(int i=0; i<newStr1.size()-1; i++){
        if((newStr1[i]>='a'&&newStr1[i]<='z')&& (newStr1[i+1]>='a'&&newStr1[i+1]<='z')){
            string s = newStr1.substr(i,2);
            s1.push_back(s);
        }  
    }
    
    for(int i=0; i<newStr2.size()-1; i++){
        if((newStr2[i]>='a'&&newStr2[i]<='z')&& (newStr2[i+1]>='a'&&newStr2[i+1]<='z')){
            string s = newStr2.substr(i,2);
            s2.push_back(s);
        }  
    }  
}

void init(string str1, string str2) {
    for(int i=0; i<str1.size(); i++){
        newStr1+=tolower(str1[i]);
    }
    for(int i=0; i<str2.size(); i++){
        newStr2+=tolower(str2[i]);
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    init(str1, str2);
    createVector(newStr1, newStr2);
    answer=calSet(s1,s2);
    
    return answer;
}