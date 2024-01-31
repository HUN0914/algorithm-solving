#include <iostream>

using namespace std;

int main(void)
{
	int n;

	cin >> n;

	int i = 1;

	while (n > i)
	{
		n -= i;
		i++;
	} //위치 계산

	if (i % 2 == 1)
	{
		cout << 1 + i - n<<"/"<<n;
	}
	else
	{
		cout << n << "/" << 1 + i - n;
	}


	/*
	
	+1해주는 이유 : 숫자의 시작이 1부터 시작이기 때문
	(분모 start : 1 , 분자 start : 1)
	
	*/
	
	return 0;
}