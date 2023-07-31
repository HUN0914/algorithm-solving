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
	int val;
	int gap = 0;
	int count = 0;

	cin >> n;

	int* level = new int[n];


	for (int i = 0; i < n; i++)
	{
		scanf("%d", &level[i]);
	}

	for (int i = n - 1; i >= 1; i--)
	{
		if (level[i] <= level[i - 1])
		{
			while (1)
			{
				if (level[i] > level[i - 1])
				{
					break;
				}
				level[i - 1]--;
				count++;
			}

		}
	}

	printf("%d", count);

	delete[] level;
}

 