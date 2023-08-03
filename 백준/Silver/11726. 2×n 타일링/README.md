*********************

쉬운 DP 문제.
구하고자 하는 값의 직전 + 직직전 값을 더한 값이 
원하는 답이 된다. [DP- 메모하기]

+++

숫자가 매우 커짐에 따라, 나눠주면서 연산할 필요가 있다.
- 모듈러 연산

https://gamedevlog.tistory.com/44
(모듈러 연산 사이트 참고)

***********************



# [Silver III] 2×n 타일링 - 11726 

[문제 링크](https://www.acmicpc.net/problem/11726) 

### 성능 요약

메모리: 2804 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 문제 설명

<p>2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.</p>

<p>아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11726/1.png" style="height:50px; width:125px"></p>

### 입력 

 <p>첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)</p>

### 출력 

 <p>첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.</p>

