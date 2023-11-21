#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int square[101][101] = { 0, };

int main(void)
{

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;

		cin >> x1>>y1>>x2>>y2;

		for (int i = y1; i <= y2; i++)
		{
			for (int j = x1; j <= x2; j++)
			{
				square[i][j]++;
			}
		}
	}

	int count = 0;

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (square[i][j] > m)
			{
				count++;
			}
		}

	}

	cout << count;

}