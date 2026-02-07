#include <iostream>
#include <string>
#include <stack>

using namespace std;

int isChecking(string s){
    stack<char>alphabet;
    
    for(int i=0; i<s.size(); i++){
        char c=s[i];
        if(!alphabet.empty()){
            char a=alphabet.top();
            if(a!=c){ alphabet.push(c); }
            else{ alphabet.pop(); }
            
        }else alphabet.push(c);
    }
    
    if(alphabet.size()/2==1) return 0;
    
    while(!alphabet.empty()){
        char c=alphabet.top();
        alphabet.pop();
        char b=alphabet.top();
        if(c!=b) return 0;
    }
    
    return 1;
}

int solution(string s)
{
    int answer = -1;
    answer=isChecking(s);

    cout << answer << endl;

    return answer;
}