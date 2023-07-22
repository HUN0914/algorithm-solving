#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;


int main(void)
{
	long long n;
	long long check = 0;
	long long count = 1;
	long long ten = 10;
	long long sum = 0;

	scanf("%lld", &n);

	while (check < n)
	{
		if (check >= ten-1)
		{
			count++;
			ten = ten * 10;
		}
		sum = sum + count;


		check++;
	}


	printf("%lld", sum);

	return 0;
}