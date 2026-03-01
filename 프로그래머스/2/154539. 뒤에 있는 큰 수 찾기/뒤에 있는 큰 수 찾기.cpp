#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> game(vector<int>numbers){
    stack<int> stk;
    vector<int>answer(numbers.size());
    
    for(int i=numbers.size()-1; i>=0; i--){
        
        while(true){
            if(stk.empty()){
                answer[i]=-1;
                break;
            }
            int topVal=stk.top();
            if(topVal>numbers[i]){
                answer[i]=topVal;
                break;
            }
            stk.pop();
        }
        stk.push(numbers[i]);
    }
    
    return answer;
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    answer=game(numbers);
    return answer;
}