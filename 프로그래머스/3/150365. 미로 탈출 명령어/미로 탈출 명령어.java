import java.util.*;

class Solution {
    
    char[] dir = {'d','l','r','u'};
    int[] dx = {1,0,0,-1};
    int[] dy = {0,-1,1,0};
    
    public String cal (int n, int m, int x, int y, int r, int c, int k) {
        
        int distance = Math.abs(x-r)+Math.abs(y-c);
        
        if(distance>k) return "impossible";
        
        if((k-distance)%2 !=0) return "impossible";
        
        StringBuilder answer = new StringBuilder();
        
        int cx=x;
        int cy=y;
        
        for(int move=1; move<=k; move++){
            
            for(int i=0; i<4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                
                if(nx<1 || nx >n || ny<1 || ny>m) continue;
                
                int remain = k-move;
                
                int dist = Math.abs(nx-r)+ Math.abs(ny-c);
                
                if(dist>remain) continue;
                if((remain-dist)%2!=0) continue;
                                
                answer.append(dir[i]);
                cx=nx;
                cy=ny;
                break;
            }
        }
        
        return answer.toString();
    }
    
    public String solution(int n, int m, int x, int y, int r, int c, int k) {
        return cal(n, m, x, y, r, c, k);
    }
}