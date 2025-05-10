#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int temp=0;
    
    while(1){
        if(wallet[0]>=bill[0]&&wallet[1]>=bill[1] || wallet[0]>=bill[1]&&wallet[1]>=bill[0]){
            return answer;
        }
        
        if(bill[0]<bill[1]){
            bill[1]=bill[1]/2;
        }else{
            bill[0]=bill[0]/2;
        }
        answer++;
    }
}