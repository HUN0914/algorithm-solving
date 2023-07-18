#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(void)
{
	int n;
	int m;
	int val;
	int num = 1;

	int max = 1;
	int gap;
	int count = 0;

	vector<int> v;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);

		//int* grade = new int [m] {0, };

		for (int j = 0; j < m; j++)
		{
			scanf("%d", &val);
			v.push_back(val);
		}

		sort(v.begin(), v.end());

		for (int a = 0; a < v.size()-1; a++)
		{
			if (v[a] - v[a + 1] < 0)
			{
				gap = -(v[a] - v[a + 1]);
			}
			else
			{
				gap = v[a] - v[a + 1];
			}

			if (count = 0)
			{
				max = gap;
				count++;
			}
			else
			{
				if (gap > max)
				{
					max = gap;
				}
			}

			
			
		}

		printf("Class %d\n", num);
		printf("Max %d, Min %d, Largest gap %d\n", v[m - 1], v[0],max);
		num++;
		max = 0;

		v.clear();

	}

	return 0;
}