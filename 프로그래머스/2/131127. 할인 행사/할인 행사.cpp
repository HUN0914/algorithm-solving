#include <string>
#include <vector>

using namespace std;

int game(int totalCount, vector<string> want, vector<int> number, vector<string> discount) {
    
    int numberSum=0;
    int gameTotal=0;
    
    while(true){
        vector<int> copyNumber=number;
        bool check=false;
        
        if(numberSum+totalCount>discount.size()) break;
        
        for(int i= numberSum; i<numberSum+totalCount; i++){
            for(int j=0; j<want.size(); j++){
                if(want[j]==discount[i]){
                    copyNumber[j]--;
                }
            }
        }
        
        for(int i=0; i<copyNumber.size(); i++){
            if(copyNumber[i]>0){
                check=true;
                break;
            }
        }
        
        if(!check) gameTotal++;
        
        numberSum++;      
    }
    
    return gameTotal;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int totalCount=0;
    for(int i=0; i<number.size(); i++){
        totalCount+=number[i];
    }
    
    answer= game(totalCount, want, number, discount);
    
    return answer;
}