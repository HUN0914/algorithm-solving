#include <iostream>
#include <algorithm>
#include <vector>

/*

틀린 이유 : 0일 경우엔 50000 이렇게 저장하는게 아니라 아예
들어가지 않도록 해야함.
*/
using namespace std;
int n, m;
int map[103][103];
bool check[103][103];


void max_return()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 500000000;
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;

	int val1, val2;

	for (int i = 0; i < m; i++)
	{
		cin >> val1 >> val2;

		map[val1][val2] = 1;
		map[val2][val1] = 1;
		check[val1][val2] = true;
		check[val2][val1] = true;
	}

	max_return();

	for (int a = 1; a <= n; a++) //a =거쳐가는 노드
	{
		for (int b = 1; b <= n; b++) // b = 출발 노드
		{
			for (int c = 1; c <= n; c++) // c = 도착 노드
			{
				if (check[b][a] && check[a][c])
				{
					if (map[b][c] > map[b][a] + map[a][c])
					{
						map[b][c] = map[b][a] + map[a][c];

					}
					check[b][c] = true;
				}
			}
		}
	}

	//정리가 다 된 상태
	int result = 500000000;
	int sum;
	int counti = 0;
	for (int i = 1; i <= n; i++)
	{
		sum = 0;
		for (int j = 1; j <= n; j++)
		{
			sum += map[i][j];
		}
		if (sum < result)
		{
			result = sum;
			counti = i;
		}

	}

	cout << counti;


	return 0;
}