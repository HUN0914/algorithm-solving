#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>


using namespace std;


int main(void)
{
	int n, m;
	int t;
	int space[300][300] = { 0, };

	int x1, y1;
	int x2, y2;
	int sum = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> space[i][j];
		}
	}

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = x1 - 1; i < x2; i++)
		{
			for (int j = y1 - 1; j < y2; j++)
			{
				sum = sum + space[i][j];
			}
		}
		printf("%d\n", sum);
		sum = 0;

	}




}