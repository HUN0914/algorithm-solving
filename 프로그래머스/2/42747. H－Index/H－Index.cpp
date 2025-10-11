#include <string>
#include <vector>

using namespace std;

int standard=0;

int solution(vector<int> citations) {
    int answer = 0;
    
    for(int i=0; i<citations.size(); i++){
        if(citations[i]>standard) standard=citations[i];
    }
    
    while(standard>=0){
        
        int maximum=0;
        int noMaximum=0;
        
        for(int i=0; i<citations.size(); i++){
            if(citations[i]>=standard) {
                maximum++;
            }else{
                noMaximum++;
            }
        }
        if(maximum>=standard) break;
        standard--;
    }
    answer=standard;
    
    return answer;
}



/*
max값 하나 잡은다음에 그걸 기준으로 삼고
0부터 쭉 돌려서 standard(기준) 값 이상인 것들 다 카운트 (maximum)
이하인 것들다 카운트 (noMaximum)
맥시멈이 노 멕시멈 
*/