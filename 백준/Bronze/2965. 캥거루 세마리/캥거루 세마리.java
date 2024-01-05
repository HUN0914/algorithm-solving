

import java.io.BufferedReader;         // BufferedReader 클래스를 사용하기 위해 필요한 import 문
import java.io.IOException;            // IOException 클래스를 사용하기 위해 필요한 import 문
import java.io.InputStreamReader;      // InputStreamReader 클래스를 사용하기 위해 필요한 import 문
import java.util.StringTokenizer;      // StringTokenizer 클래스를 사용하기 위해 필요한 import 문

public class Main {                    // Main 클래스 정의

    public static void main(String[] args) throws IOException {   // main 메서드 시작, IOException 처리 선언

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  // BufferedReader 객체 생성 및 표준 입력으로부터 데이터를 읽기 위한 InputStreamReader로 래핑
        StringTokenizer st = new StringTokenizer(br.readLine());  // 한 줄을 읽어 StringTokenizer 객체를 생성하고, 문자열을 공백을 기준으로 토큰으로 나눔

        int A = Integer.parseInt(st.nextToken());  // 첫 번째 토큰을 정수로 변환하여 변수 A에 저장
        int B = Integer.parseInt(st.nextToken());  // 두 번째 토큰을 정수로 변환하여 변수 B에 저장
        int C = Integer.parseInt(st.nextToken());  // 세 번째 토큰을 정수로 변환하여 변수 C에 저장

        // 큰 값을 구해서 max에 저장
        int max = Math.max((B - A), (C - B));  // (B - A)와 (C - B) 중 큰 값을 구하여 max 변수에 저장

        // 설명에서처럼 값에 -1을 해서 출력
        System.out.println(max - 1);  // max에서 1을 뺀 값을 출력
    }
}
