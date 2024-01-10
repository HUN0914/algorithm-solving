***********

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int a, b;
queue<int>q;
int cnt = 0;



int bfs(int something)
{
	q.push(a);

	while (!q.empty())
	{
		

		int something = q.front();
		
		if (something == b)
		{
			return cnt;
		}


		q.pop();

		if (something > b) continue;

		for (int i = 0; i < 2; i++)
		{
			if (i == 0)
			{
				int mul = something * 2;

				q.push(mul);
			}
			else
			{
				string right = to_string(something) + "1";
				int val_right = stoi(right);

				q.push(val_right);

			}
		}
		
		cnt++;
	}

	return -1;

}

int main(void)
{
	cin >> a >> b;

	cout << bfs(a);


	

	return 0;
}


* 이때는 모든 경우에 대해 탐색하니까 안되는것
반복문 때문에 최악의 경우 탐색 횟수 *2가 됨 *


string right = to_string(something) + "1";
int val_right = stoi(right);


    to_sring(어떤변수)를 해주면 string형으로 바뀌고 + "1" 해주면 바로 뒤에
    1이 붙는다 (ex : 1234 )->to string 후 +1 => 12345
    stoi(string 형) 을 하면 string 형 변수가 int형으로 바뀐다.

    근데 왜 여기선 런타임 에러가 나와;;

***********

# [Silver II] A → B - 16953 

[문제 링크](https://www.acmicpc.net/problem/16953) 

### 성능 요약

메모리: 2152 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색, 그리디 알고리즘

### 제출 일자

2024년 1월 10일 17:12:19

### 문제 설명

<p>정수 A를 B로 바꾸려고 한다. 가능한 연산은 다음과 같은 두 가지이다.</p>

<ul>
	<li>2를 곱한다.</li>
	<li>1을 수의 가장 오른쪽에 추가한다. </li>
</ul>

<p>A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.</p>

### 입력 

 <p>첫째 줄에 A, B (1 ≤ A < B ≤ 10<sup>9</sup>)가 주어진다.</p>

### 출력 

 <p>A를 B로 바꾸는데 필요한 연산의 최솟값에 1을 더한 값을 출력한다. 만들 수 없는 경우에는 -1을 출력한다.</p>

