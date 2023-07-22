#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

char n[100000] = { 0, };

int main(void)
{
	vector<char> num;
	long long sum = 0;

	scanf("%s", n);

	for (int i = 0; i < strlen(n); i++)
	{
		sum = sum+n[i] - '0';
	}

	if (sum % 3 == 0)
	{
		sort(n, n + strlen(n));
		if (n[0] != '0')
		{
			printf("-1");
		}
		else
		{
			for (int i = strlen(n) - 1; i >= 0; i--)
			{
				printf("%c", n[i]);
			}
		}
	}
	else
	{
		printf("-1");
	}








	return 0;
}