import java.util.Scanner;
import java.io.FileInputStream;
import java.util.*;
import java.io.*;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{
	
	 static boolean game(int[] arr, int M, int K) {
				 
		int fishCnt=0;
		int time=0;
		int arrCnt=0;
		Arrays.sort(arr);
		
		
		while(true) {
			if(time>arr[arr.length-1]) break;
			
			if(arr[arrCnt]<=time) { 
				
				// 같은 초일때 
				int same=1;
				for(int cur=arrCnt; cur<arr.length-1; cur++) {
					if(arr[cur]!=arr[cur+1]) break;
					same++;
				}
				
				if(fishCnt<same) return false;
				else {
					fishCnt-=same;
					arrCnt+=same;
				}
			}
			
			time++;
			if(time>0&&time%M==0) fishCnt+=K;
			
			
		}
		
		return true;
	}
	
	/*
	 * 
	 * N M K 주어지고 N명의 사람이 기다림 없이 먹어지는지?
	 * M : M초의 시간동안 K개 만들어짐
	 * 2명의 사람이 오는데 2초에 2개 만들어
	 * 완탐으로 cnt 쭉 돌려서 마지막 사람 cnt까지 갔을때 붕어빵 있는지 확
	 * 
	 */
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T=Integer.parseInt(st.nextToken());
		/*
		   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
		*/

		for(int test_case = 1; test_case <= T; test_case++)
		{
			
			st = new StringTokenizer(br.readLine());
			
			int N= Integer.parseInt(st.nextToken());
			int M= Integer.parseInt(st.nextToken());
			int K= Integer.parseInt(st.nextToken());
			
			int[] arr= new int[N];
			
			st = new StringTokenizer(br.readLine());

			for(int i=0; i<N; i++) {
				
				arr[i]=Integer.parseInt(st.nextToken());
			}
			
			StringBuilder sb = new StringBuilder();
			
			if(game(arr,M,K)){
				sb.append("#")
				.append(test_case)
				.append(" ")
				.append("Possible");
				
				System.out.println(sb);
			}else
			{
				sb.append("#")
				.append(test_case)
				.append(" ")
				.append("Impossible");

				System.out.println(sb);

			}
			
		}
	}
}