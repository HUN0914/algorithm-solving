#include <string>
#include <vector>

using namespace std;
bool isVisited[21];
int result=0;

void dfs(vector<int> numbers, int target, int cnt, int curValue){
    if(cnt==numbers.size()) {
        if(curValue==target) result++;
        return;
    }
    dfs(numbers,target,cnt+1,curValue+numbers[cnt]);
    dfs(numbers,target,cnt+1,curValue-numbers[cnt]);
    
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target, 0,0);
    int answer = result;
    return answer;
}