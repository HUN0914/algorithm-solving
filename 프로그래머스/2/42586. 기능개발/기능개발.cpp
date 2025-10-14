#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> checking;
    
    bool isTrue[progresses.size()];
    
    for(int i=0; i<progresses.size(); i++){
        isTrue[i]=false;
    }
    
    while(progresses.size()>0){
        int newCount=0;
        
        for(int i=0; i<progresses.size(); i++){
        progresses[i]=progresses[i]+speeds[i];
            
        }
        
        int value=0;
        while(progresses.size()>0){
            if(progresses[value]>=100){
                newCount++;
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
            }else{
                break;
            }
    
        } 
        if(newCount>0){
        answer.push_back(newCount);   
        }
        
    }
    return answer;
}

/*
bool 처리해서 만약 100 이상일 경우 값을 true 처리하게 시킴

그리고 매 순환을 돌 때마다 만약 false인 값이 있으면 return 금지 계속 ++ 해주기
제일 마지막 순간의 true이면서 -1이 아닌 위치를 기록
처음부터 그 위치까지 다 false이면 넣기
pop.front() 해줘야할듯
*/