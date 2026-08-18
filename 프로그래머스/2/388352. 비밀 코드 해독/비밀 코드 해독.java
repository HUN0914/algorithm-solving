import java.util.*;

class Solution {

    public int Cnt=0;
    boolean[] isNumber = new boolean[31];
    
    public boolean isCheck(int[][]q, int[] ans, List<Integer> de){
                
        for(int i=0; i<q.length; i++){
            int sameCnt=0;
            for(int j=0; j<q[i].length; j++){
                for(int k=0; k<de.size(); k++){
                    if(de.get(k)==q[i][j]){
                        sameCnt++;
                        break;
                    }
                }
            }
            if(ans[i]!=sameCnt) return false;
        }

        return true;
    }
    
    public void cal(int n, int[][]q, int[] ans, List<Integer> de, int cur){
        if(de.size()==5){
            if(isCheck(q,ans,de)) Cnt++;
            return;
        }
        
        for(int i=cur; i<=n; i++){
            if(isNumber[i]) continue;
            isNumber[i]=true;
            de.add(i);
            cal(n,q,ans,de,i+1);
            de.remove(de.size()-1);
            isNumber[i]=false;
        }
    }
    
    public int solution(int n, int[][] q, int[] ans) {
        List<Integer> de = new ArrayList<>();
        
        cal(n,q,ans,de,1);
        
        return Cnt;
    }
}