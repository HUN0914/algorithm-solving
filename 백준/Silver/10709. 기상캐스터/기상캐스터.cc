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
	int h;
	int w;
	char square[100][100] = { 0, };
	int count = 0;

	int space[100][100] = { 0, };

	cin >> h >> w;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> square[i][j];
		}

	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (square[i][j] == '.')
			{
				if (count == 0)
				{
					space[i][j] = -1;
				}
				else
				{
					space[i][j] += count;
					count++;
				}

			}
			if (square[i][j] == 'c')
			{
				count++;
				space[i][j] == 0;
				if (count != 1)
				{
					count = 1;
				}
	
			}
			
		}
		count = 0;

	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << space[i][j]<<" ";
		}
		printf("\n");
	}




}
 