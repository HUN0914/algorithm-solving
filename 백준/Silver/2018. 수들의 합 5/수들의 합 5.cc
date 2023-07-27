#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <math.h>


using namespace std;

//int sum[10000000] = { 0, };

int main() {

	int n;
	int count = 0;


	int start = 1;
	int end = 1;
	int result = 0;

	cin >> n;

	//int* sum = new int[n];

	//for (int i = 0; i < n; i++)
	//{
	//	sum[i] = i + 1;
	//}

	result = 1;
	while (end < n)
	{
		if (result < n)
		{
			end++;
			if (end < n)
			{
				result += end;
			}
		}
		else if (result > n)
		{
			start++;
			end = start + 1;
			result = start;

			if (end < n)
			{
				result += end;
			}

		}
		else if (result == n)
		{
			start++;
			end = start + 1;
			result = start;

			if (end < n)
			{
				result += end;
			}
			count++;
		}

	}

	

	printf("%d", count+1);

	//delete[] sum;

	return 0;

}
 