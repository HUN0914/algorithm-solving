#include <iostream>

using namespace std;

int game(int a, int b){
    
    int cnt=0;
    int newA=max(a,b);
    int newB=min(a,b);
    
    
    while(newA!=newB){
        if(newA%2!=0) newA+=1;
        if(newB%2!=0) newB+=1;
        if(newA>1) { newA=newA/2;}
        
        newB=newB/2;
        cnt++;
    }
    return cnt;
}

int solution(int n, int a, int b)
{
    int answer = game(a,b);

    cout << answer << endl;

    return answer;
}