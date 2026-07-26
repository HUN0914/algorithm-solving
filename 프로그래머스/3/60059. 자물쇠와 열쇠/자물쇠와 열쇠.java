import java.util.*;

/*

좌물쇠 홈 파여있고 열쇠도 홈 돌기 존재

좌물쇠 영역 내에서 
열쇠의 돌기 부분과 좌물쇠의 홈 부분 정확히 일치
열쇠의 돌기와 좌물쇠의 돌기 만나선 안됨

돌기가 뭔데?
홈 : 0인 부분
돌기 : 1인 부분
 
열쇠 1 : 좌물쇠 1 만나면 안됨

1. 회전 (시계 / 반시계 회전 만들기)
2. 이동 로직 만들기 (상,하,좌,우)
3. 돌기 만나는지 확인하는 로직

범위가 20이면 5중 반복문으로도 가능하다.
4*39*39*20*20 = 숫자 별로 안됨 (1000만도 안됨)

*/

class Solution {
    
    int[][] rotateClock(int[][]original){
        
        int row = original.length;
        int col = original[0].length;
        
        int[][] rotated = new int [col][row];
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                rotated[j][row-1-i]=original[i][j];
            }
        }
        
        return rotated;
    }
    
    boolean checkKey(int[][]key, int[][] lock, int startY, int startX){
        
        int keyWidth=key[0].length;
        int keyHeight=key.length;
        
        int lockWidth=lock[0].length;
        int lockHeight=lock.length;
        
        int[][] copiedLock = new int[lockHeight][lockWidth];
        
        for(int i=0; i<lockHeight; i++)
            for(int j=0; j<lockWidth; j++)
                copiedLock[i][j] = lock[i][j];
        
        for(int i=0; i<keyHeight; i++){
            for(int j=0; j<keyWidth; j++){
                int lockY=i+startY;
                int lockX=j+startX;
                
                if(lockY<0 || lockX<0 ||
                  lockY >= lockHeight || lockX >= lockWidth) continue;
                
                copiedLock[lockY][lockX] += key[i][j];
            }
        }
        
        for(int i=0; i<lockHeight; i++){
            for(int j=0; j<lockWidth; j++){
                if(copiedLock[i][j]!=1) return false;
            }
        }

        return true;
    }
    

    public boolean game(int[][]key ,int[][] lock){
        
        int[][] current = key;
        for(int rotate=0; rotate<4; rotate++){
            if(rotate>0) current = rotateClock(current);
            
            int[][] copiedLock= lock;
            int width = current[0].length;
            int height = current.length;
            
            int lockWidth=lock[0].length;
            int lockHeight=lock.length;
            
            boolean isCheck=false;

        for(int i = -(height - 1); i < lockHeight; i++){
            for(int j = -(width - 1); j < lockWidth; j++){
                    if(checkKey(current, lock, i,j)) return true;
                }
            }
        }
        return false;
    }
    
    public boolean solution(int[][] key, int[][] lock) {
        boolean answer = game(key,lock);
        return answer;
    }
}