import java.util.*;
/*
dfs -> 시간초과 
s / n 먼저 선행 

n>s면 -1
그게 0이면 그 값 n/s n개 리턴하고
그게 아니면 그 값에서 나눈 값들만큼 +하기
근데 나눈 값이 늘 떨어지는 값이 아니기 때문에 이에 대한 처리가 필요

/n하고
%n

8 (3)
2 2 2
나오고 +2가 남으니까(이를 cnt로 저장)
이만큼 처음부터 +1해서 저장 

1. 처음 나누고
2. arr 배열에 n까지 한 크기로 만든 후에 /n한 값들 다 저장
3. 배열 계속 %n으로 하면서 무한 순회하면서 값 cnt가 0될때까지 추가
*/

class Solution {
    
    public int[] cal(int n, int s){
        
        if(n>s){
            int[] returnVal= new int[1];
            returnVal[0]=-1;
            
            return returnVal;
        }   
        
        int[] answer = new int[n];
        
        int initVal=s/n;
        int initDiv=s%n;
        
        if(initDiv==0){
            for(int i=0; i<n; i++) answer[i]=initVal;
            return answer;
        }
        
        for(int i=0; i<n; i++) answer[i]=initVal;
        
        int cnt=0;
        while(initDiv>0){
            answer[cnt%n]++;
            cnt++;
            initDiv--;
        }
        
        Arrays.sort(answer);
        
        return answer;
            
    }
    
    public int[] solution(int n, int s) {
        int[] answer = cal(n,s);
        return answer;
    }
}