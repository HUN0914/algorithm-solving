#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

int main() {
	int n;

	int one;
	int two;
	int count = 0;

	cin >> n >> one >> two;

	while (1)
	{
		if (count > 16)
		{
			printf("-1");
			break;
		}
		else
		{
			one = (one + 1) / 2;
			two = (two + 1) / 2;
			count++;
			if (one == two)
			{
				printf("%d", count);
				break;
			}

		}
	}


}

 