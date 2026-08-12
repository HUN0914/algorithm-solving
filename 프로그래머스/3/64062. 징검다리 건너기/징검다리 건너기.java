import java.util.*;

class Solution {
    
    public int cal(int[]stones, int k){
        
        int start=1;
        int end=200000000;
        int answer=0;
        
        while(start<=end){
            
            int mid=(start+end)/2;
            int curZero=0;
            int maxZero=0;
            
            for(int i=0; i<stones.length; i++){
                if(stones[i]>=mid) curZero=0;
                else if (stones[i]<mid) {
                    curZero++;
                    maxZero=Math.max(maxZero, curZero);
                }
            }
            if(maxZero<k){
                start=mid+1;
                answer=mid;
            }else {
                end=mid-1;
            }
        }
        
        return answer;
    }
    
    public int solution(int[] stones, int k) {
        int answer = cal(stones,k);
        return answer;
    }
}