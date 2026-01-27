#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long stringToNumber(string s){
    long long rank=0;
    long long p26=1;
    for(int i=0; i<s.length()-1; i++){
        p26*=26;
        rank+=p26;
    }
    
    long long curPos=0;
    for(int i=0; i<s.length(); i++){
         curPos=curPos*26+(s[i]-'a');
    }
    
    return rank+curPos+1;
}

string numberToString(long long n){
    int len=1;
    long long p26=26;
    
    while(n> p26){
        n-=p26;
        p26*=26;
        len++;
    }
    
    n--;
    string s="";
    for(int i=0; i<len; i++){
        s= (char)('a'+(n%26)) +s;
        n/=26;
    }
    return s;
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    long long answerN=n;
    
    vector<long long> bansRank;
    
    for(auto & val : bans){
        bansRank.push_back(stringToNumber(val));
    }
    
    sort(bansRank.begin(),bansRank.end());
    
    for(auto & val :bansRank){
        if(val<=answerN) answerN++;
        else break;
    }
    
    answer=numberToString(answerN);
    
    return answer;
}