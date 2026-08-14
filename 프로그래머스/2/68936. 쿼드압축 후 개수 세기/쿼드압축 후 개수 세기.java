import java.util.*;

class Solution {
    
    public int[] answer= new int[2];
    
    public void squeeze(int[][] arr, int x, int y, int length){
        if(zipChk(arr,x,y,length,arr[x][y])) {
            if(arr[x][y]==1) answer[1]++;
            else answer[0]++;
            return;
        }
        
        squeeze(arr,x,y,length/2);
        squeeze(arr,x+length/2,y,length/2);
        squeeze(arr,x,y+length/2, length/2);
        squeeze(arr,x+length/2,y+length/2,length/2);
    }
    
    public boolean zipChk(int[][] arr, int x, int y, int length, int arrVal){
        for(int i=x; i<x+length; i++){
            for(int j=y; j<y+length; j++){
                if(arrVal!=arr[i][j]) return false;
            }
        }
        return true;
    }
    
    public int[] solution(int[][] arr) {
        squeeze(arr,0,0,arr.length);
        return answer;
    }
}