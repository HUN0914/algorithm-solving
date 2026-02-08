#include <string>
#include <vector>
#include <stack>

using namespace std;

int checkString(string s){
    stack<char> st;
    
    for(auto & val : s){
        if(st.empty()){
            if(val==']'||val==')'||val=='}') return 0;
            st.push(val);
        }else{
            if(st.top()=='['){
                if(val==']'){ st.pop(); }
                else if (val==')'||val=='}') return 0;
                else st.push(val);
            }
            else if(st.top()=='('){
                if(val==')'){ st.pop(); }
                else if (val==']'||val=='}') return 0;
                else st.push(val);
            }
            else if(st.top()=='{'){
                if(val=='}'){ st.pop(); }
                else if (val==')'||val==']') return 0;
                else st.push(val);
            }            
        }
    }
    
    if(!st.empty()) return 0;
    else return 1;
}


int game(string s){
    int total=0;
    
    for(int i=0; i<s.size(); i++){
        string answer;
        int value=i;
        while(true){
            if(answer.size()==s.size()) break;
            answer+=s[value%s.size()];
            value++;
        }
        
        total+=checkString(answer);
    }
    
    return total;
}
//[{]}

int solution(string s) {
    int answer = -1;
    answer=game(s);
    
    return answer;
}