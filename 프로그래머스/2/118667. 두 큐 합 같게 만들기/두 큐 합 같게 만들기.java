import java.util.*;

class Solution {
        
    public long cal(int[] queue1, int[] queue2){
         long totalVal=0;
         long oneVal=0;
         long[] totalArr=new long[queue1.length*2];
        
        for(int i=0; i<queue1.length; i++){
            totalVal+=queue1[i];
            oneVal+=queue1[i];
            totalArr[i]=queue1[i];
        }
        
        for(int i=0; i<queue2.length; i++){
            totalVal+=queue2[i];
            totalArr[i+queue1.length]=queue2[i];
        }
        
        int start=0;
        int end=queue1.length;
        int cnt=0;
        
        while(end<2*queue1.length){
            if(oneVal==totalVal/2) return cnt;
            
            if(oneVal>totalVal/2){
                oneVal-=totalArr[start];
                start++;
                cnt++;
            }
            
            if(oneVal<totalVal/2){
                oneVal+=totalArr[end];
                end++;
                cnt++;
            }
        }
        
        return -1;
    }
    
    public long solution(int[] queue1, int[] queue2) {
        return cal(queue1, queue2);
    }
}