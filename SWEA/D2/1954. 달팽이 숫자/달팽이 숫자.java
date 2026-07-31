import java.util.Scanner;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.*;

/*
사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
*/
class Solution
{
public static void main(String args[]) throws Exception
{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
int T;
T=Integer.parseInt(br.readLine());

/*
여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
*/

int[] dy = {0,1,0,-1};
int[] dx= {1,0,-1,0}; //오, 아, 왼, 위 방향


for(int test_case = 1; test_case <= T; test_case++)
{
	
	int n = Integer.parseInt(br.readLine());
		
	int[][] board = new int[n][n];	
	int y=0;
	int x=0;
	int nDir=0;
	int cnt=1;
	
	while(true) {
		if(cnt==n*n) break;
		board[y][x]=cnt;
				
		int py=y+dy[nDir];
		int px=x+dx[nDir];
		
		if(py<0||py>=n
			||px<0||px>=n
			||board[py][px]!=0) {
			nDir=(nDir+1)%4;
			continue;
		}
		
		cnt++;
		y=py;
		x=px;
	}
	board[y][x]=n*n;
	
	System.out.print("#"+test_case);
	System.out.println();
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			System.out.print(board[i][j]+" ");
		}
		System.out.println();
	}
}
}
}
