#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int triangle[501][501];
int n;

int dp_left = 0;
int dp_right = 0;

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> triangle[i][j];
		}
	}
	//int dp_left[501];
	//int dp_right[501];

	//dp_left[0]= triangle[0][0];
	//dp_right[0] = triangle[0][0];


	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			triangle[i - 1][j] =triangle[i-1][j]+ max(triangle[i][j], triangle[i][j + 1]);
		}
	}

	cout << triangle[0][0];



	return 0;
}
