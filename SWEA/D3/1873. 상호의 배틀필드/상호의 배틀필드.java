/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// double b;
// char g;
// String var;
// long AB;
// a = sc.nextInt();                           // int 변수 1개 입력받는 예제
// b = sc.nextDouble();                        // double 변수 1개 입력받는 예제
// g = sc.nextByte();                          // char 변수 1개 입력받는 예제
// var = sc.next();                            // 문자열 1개 입력받는 예제
// AB = sc.nextLong();                         // long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// double b = 1.0;               
// char g = 'b';
// String var = "ABCDEFG";
// long AB = 12345678901234567L;
//System.out.println(a);                       // int 변수 1개 출력하는 예제
//System.out.println(b); 		       						 // double 변수 1개 출력하는 예제
//System.out.println(g);		       						 // char 변수 1개 출력하는 예제
//System.out.println(var);		       				   // 문자열 1개 출력하는 예제
//System.out.println(AB);		       				     // long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
import java.util.Scanner;
import java.io.FileInputStream;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */

/*
 * 나와야 할 함수 
 * 1. init (보드 값)
 * 2. struct tank (y,x좌표, 방향)
 * 3. 포탄 계산 
 * 
 */
class Solution
{
	static char[][] board = new char[21][21];
	static char[] order = new char[101];
	static int cur;
	static int row;
	static int orderSize;
	
	static int[] dy = {-1,1,0,0}; //up, down, left, right
	static int[] dx = {0,0,-1,1};
	
	static class Tank{
		int y;
		int x;
		int dir;
		
		Tank() {}
		
		Tank(int y, int x, int dir){
			this.y=y;
			this.x=x;
			this.dir=dir;
		}
	}
	
	static Tank tank = new Tank();
	
	public static void shoot() {
		int y=tank.y;
		int x=tank.x;
		int dir=tank.dir;
		
		while(true) {
			int ny=y+dy[dir];
			int nx=x+dx[dir];
			
			if(ny<0||ny>=cur||nx<0||nx>=row) break;
			
			if(board[ny][nx]=='#') break;
			
			if(board[ny][nx]=='*') {
				 board[ny][nx] = '.';
				 break;				
			}
			y=ny;
			x=nx;
		}
	}
	
	public static void move() {
		
		int y=tank.y;
		int x=tank.x;
		int dir=tank.dir;

		if(dir==0) board[y][x]='^';
		if(dir==1) board[y][x]='v';
		if(dir==2) board[y][x]='<';
		if(dir==3) board[y][x]='>';
		
		int ny=y+dy[dir];
		int nx=x+dx[dir];
		
		if(ny<0||ny>=cur||nx<0||nx>=row) return;
		if(board[ny][nx]=='-') return;
		
		if(board[ny][nx]=='.') {
			tank.y=ny;
			tank.x=nx;
			board[ny][nx]=board[y][x];

			board[y][x]='.';
		}
		
	}
	
	public static void game() { //여기서 움직이는 명령어이면 tank dir 변경!
		for(int i=0; i<orderSize; i++) {
			//output();
			//System.out.println("\n\n");

			if(order[i]=='U') {
				tank.dir=0;
				move();				
			}else if (order[i]=='D') {
				tank.dir=1;
				move();
			}else if (order[i]=='L') {
				tank.dir=2;
				move();				
			}else if (order[i]=='R') {
				tank.dir=3;
				move();				
			}else if (order[i]=='S') {
				shoot();
			}
		}
	}
	
	public static void output() {
		for(int i=0; i<cur; i++) {
			for(int j=0; j<row; j++) {
				System.out.print(board[i][j]);
			}
			System.out.println();
		}
	}
	
	public static void main(String args[]) throws Exception
	{
		/*
		   아래의 메소드 호출은 앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
		   여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
		   이 코드를 프로그램의 처음 부분에 추가하면 이후 입력을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
		   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 메소드를 사용하셔도 좋습니다.
		   단, 채점을 위해 코드를 제출하실 때에는 반드시 이 메소드를 지우거나 주석 처리 하셔야 합니다.
		 */
		//System.setIn(new FileInputStream("res/input.txt"));

		/*
		   표준입력 System.in 으로부터 스캐너를 만들어 데이터를 읽어옵니다.
		 */
		
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		/*
		   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
		*/

		for(int test_case = 1; test_case <= T; test_case++)
		{
			cur=sc.nextInt();
			row=sc.nextInt();
			
			String s;

			for(int i=0; i<cur; i++) {
				s=sc.next();

				for(int j=0; j<s.length(); j++) {
					char c = s.charAt(j);
					if(c=='^'||c=='v'||c=='<'||c=='>') {
						tank.y=i;
						tank.x=j;
						
						if(c=='^') tank.dir=0;
						else if(c=='v') tank.dir=1;
						else if (c=='<') tank.dir=2;
						else if (c=='>') tank.dir=3;
						
						
						//board[i][j]='.';
						
					}
					board[i][j]=s.charAt(j);
				}
			}
			
			orderSize=sc.nextInt();
			
			s=sc.next();
			for(int i=0; i<s.length(); i++) {
				order[i]=s.charAt(i);
			}
			
			game();
			System.out.print("#"+test_case+" ");
			output();
			
		}
	}
}