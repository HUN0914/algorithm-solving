#define _CRT_SECURE_NO_WARNINGS
#include  <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int t;
	vector<int> v;

	scanf("%d", &t);

	priority_queue<int, vector<int>, greater<int>> pq;

	int val;

	for (int i = 0; i < t; i++)
	{
		scanf("%d", &val);

		if (val == 0)
		{
			if (pq.empty())
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else
		{
			pq.push(val);
		}

	}


	
}