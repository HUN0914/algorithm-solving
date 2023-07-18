#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{	
	long long width = 2;
	long long high = 1;
	long long front_width;
	long long front_high;
	long long sum = 0;
	int n;

	cin >> n;


	if (n == 1)
	{
		printf("4");
	}
	else if (n == 2)
	{
		cout << 2 + 2 + 1 + 1;
	}
	else
	{

		for (int i = 0; i < n-1; i++)
		{
			sum = (width * 2) + (high * 2);
			front_width = width;
			front_high = high;
			
			high = width;
			width = width + front_high;

		}
		cout << sum;

	}


	return 0;
}