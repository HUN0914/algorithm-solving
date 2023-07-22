#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int t;
	int stan;
	int count = 0;
	int num = 0;

	int checking = 0;
	int naa = 0;
	//cin >> t;
	scanf("%d", &t);

	int* test = new int[t] {0};
	//cin >> stan;
	scanf("%d", &stan);
	for (int i = 0; i < t-1; i++)
	{
		cin >> test[i];
		if (test[i] == stan)
		{
			naa++;
		}
	}

	//if (naa == t - 1)
	//{
	//	if (t == 1)
	//	{
	//		printf("0");
	//	}
	//	else
	//	{
	//		printf("1");
	//	}
	//}
	if (t == 1)
	{
		printf("0");
	}
	else
	{

		sort(test, test + (t - 1));

		while (1)
		{
			if (stan  > test[t - 2])
			{
				break;
			}
			else
			{
\
				sort(test, test + t-1);
				test[t - 2]--;
				stan++;
				count++;
			}

		}

		for (int i = 0; i < t - 1; i++)
		{
			//cout << test[i] << " ";
			if (stan == test[i])
			{
				checking = 1;
			}
			//여기서 중복일때 그 값들만 +해주자
		}

		printf("%d",count + checking);
	}

	delete[] test;
}


/*
0 10 10 10 10 10 10 10 10
예제 오류 발생

제일 큰 값을 기준으로 기준값 +1>제일 큰 값 -1인가?
무한 솔트 돌리면될것같은데

예제 4

6	9
7	8
8	7으로 하면
8이란 값 하나가 더 존재해서 문제임
-->해결하자

*/