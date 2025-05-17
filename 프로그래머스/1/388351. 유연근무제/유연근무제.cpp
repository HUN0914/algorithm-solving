#include <string>
#include <vector>

using namespace std;
/*
토,일은 무시 + 평일에만 +10까지 출근하면 됨
토,일의 구분조건 : %7을 했을때 6 or 0이면 토,일임
1050 -> 1100 인것도 생각을 해야함. : schedule%100>=50일경우엔 
schedule+100 / schedule -50 ==> schedule+50
if(schedule%100>=50) 범주가 거기
반복문돌려서 만약 schedule 범주 안에 포함되어있지 않다면 boolean을 false처리
23시일때는 어떻게하냐 -> if(schedules>=2350)일때, schedule<=x<=schedule+50-2400 
*/
int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int num=0;
    int checking[schedules.size()];
    for(int i=0; i<schedules.size(); i++){
        checking[i]=0;
    }
    
    
    vector<int> max_schedules;
    for(int i=0; i<schedules.size(); i++){
        if(schedules[i]%100>=50){
            if(schedules[i]>=2350){
                num = schedules[i]+50-2400;
            }else{
                num = schedules[i]+50;
            }
                max_schedules.push_back(num);
        }else
        {
            max_schedules.push_back(schedules[i]+10);
        }
    }
    
    
    
    for(int i=0; i<schedules.size(); i++){
        int day=0;
    while(day<7){
        if((startday+day)%7==6||(startday+day)%7==0) {
            day++;
            continue;
        }
       if(max_schedules[i]<timelogs[i][day]){
            checking[i]++;
        }
        day++;
    }
    }
    
    
    for(int i=0; i<schedules.size(); i++){
        if(checking[i]==0){
            answer++;
        }
    }
    
    return answer;
}