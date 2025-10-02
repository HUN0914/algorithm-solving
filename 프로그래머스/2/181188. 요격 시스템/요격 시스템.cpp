#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int>&v1, const vector<int>&v2){
    if(v1[1]==v2[1]){
        return v1[0]<v2[0];
    }
    return v1[1]<v2[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end(), compare);
    
    int starting=targets[0][1];

    
    for(int i=1; i<targets.size(); i++){
        if(targets[i][0]<starting){
            continue;
        }else{
            answer++;
            starting=targets[i][1];
        }
    }

    
    return answer;
}
