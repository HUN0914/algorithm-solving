import java.io.*;
import java.util.*;
import java.util.Scanner;
import java.io.FileInputStream;


class Solution
{
	
	static int game(int[] arr) {
		Set<Integer> s = new HashSet<Integer>();
		
		s.add(0);
		
		for(int value : arr) {
			List<Integer> li = new ArrayList<Integer>();
			
			for(int sVal : s) {
				li.add(value+sVal);
			}
			s.addAll(li);
		}
	
		return s.size();
		
	}
	
	
public static void main(String args[]) throws Exception
{

	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));    
	int T =Integer.parseInt(br.readLine());

	for(int test_case = 1; test_case <= T; test_case++)
	{
		
		StringBuilder sb = new StringBuilder();
		
		int n = Integer.parseInt(br.readLine());
    	StringTokenizer st = new StringTokenizer(br.readLine());
		
		int[] arr = new int[n];
		
		for(int i=0; i<n; i++) {
			arr[i]=Integer.parseInt(st.nextToken());
		}
		
		sb.append("#")
		.append(test_case)
		.append(" ")
		.append(game(arr));
		
		System.out.println(sb);
	
	}
}
}