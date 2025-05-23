#include <string>
#include <vector>

using namespace std;

/*
k시간동안만 운행
m보다 작을때는 서버 증설 X
k 시간 지났을 땐 증설 --
queue로 1개씩 넣고 특정 시간 지날때마다 pop연산
만약 이용자 수 / m(인원 늘어날때 기준 ) > q.size()
이면 그 값만큼 q.push

*/

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<pair<int,int>> v;
    
    
    for(int i=0; i<players.size(); i++){
            
        for(int j=0; j<v.size(); j++){
            v[j].first--;
        }
        
        if(players[i]>=m){
            int exist_server=0;
             for(int q=0; q<v.size(); q++){
                 if(v[q].first>0){
                    exist_server+=v[q].second;
                 }
             }
            int add_server=players[i]/m-exist_server;
           if(add_server>0){
              v.push_back({k,add_server});
              answer+=add_server;
            }
           }

    }
    
    return answer;
}