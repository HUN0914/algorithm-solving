#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int counting=0;
    set<int>s;
    
    for(int i=0; i<elements.size(); i++){
        s.insert(elements[i]);
    }
    
    while(counting<elements.size()){
        
        for(int j=0; j<elements.size(); j++){
            int goSum=elements[j];
            int backSum=elements[j];
            
            for(int i=1; i<=counting; i++){ //j+i로 들어가기
                
                if(j+i>=elements.size()){
                    goSum+=elements[j+i-elements.size()];
                }else{    
                    goSum+=elements[j+i];
                }
                if(j-i<0){
                    backSum+=elements[j-i+elements.size()];
                }else{
                    backSum+=elements[j-i];
                }
            }
            
            s.insert(goSum);
            s.insert(backSum);
            
        }
        
        counting++;
    }
    
    answer=s.size();
    
    return answer;
}
//중복 값 제외 -> 반복문으로 해결해야하는문제, set으로 값 받으면 될듯 그리고 set크기 반환
//양옆 값 비교, 만약 -1 하거나 +1 했을 때 사이즈보다 크거나 음수다 -> 크기-1 위치로 반환 (반복문2번?3번?)
//여기서 앞으로(+), 뒤로(-)다 계산 값이 -일경우 그 값 + size, 그리고 이걸 모든 수에 다해주면 됨 