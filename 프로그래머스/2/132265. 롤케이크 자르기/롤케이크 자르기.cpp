#include <string>
#include <vector>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    vector<int> right(10001,0);
    vector<int> left(10001, 0);
    
    int rightKind=0;
    int leftKind=0;
    
    for(auto i : topping){
        if(right[i]==0) rightKind++;
        right[i]++;
    }
    
    for(int i=0; i<topping.size()-1; i++){
        int value=topping[i];
        if(left[value]==0) leftKind++;
        left[value]++;
        
        right[value]--;
        if(right[value]==0) rightKind--;
        
        if(leftKind==rightKind) answer++;
    }
    
    return answer;
}