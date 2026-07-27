import java.util.*;

class Solution {
    
    int cal(int[][] scores){
        
        int answer=1;
        
        int[] numbers = new int[200001];
        
        int first=scores[0][0];
        int second=scores[0][1];
        
        Arrays.sort(scores, (o1,o2) -> {
            if(o1[0]==o2[0]) return Integer.compare(o1[1],o2[1]);
            return Integer.compare(o2[0],o1[0]);
        });
        
        int maximum=-1;
        
        for(int i=0; i<scores.length; i++){
            
            if(scores[i][1]<maximum){
                if(scores[i][0]==first&&scores[i][1]==second) return -1;

            }else{
                numbers[scores[i][0]+scores[i][1]]++;
                
                maximum=Math.max(maximum,scores[i][1]);
            }
        }
        
        for(int i=first+second+1; i<200001; i++){
            answer+=numbers[i];
        }
        
        return answer;
    }
    
    public int solution(int[][] scores) {
        int answer = cal(scores);
        return answer;
    }
}