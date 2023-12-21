#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	priority_queue<int>pq;

	int n;
	int val;
	int something;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val);

		if (val == 0)
		{
			if (!pq.empty())
			{
				something = pq.top();
				printf("%d\n", something);
				pq.pop();
			}
			else
			{
				printf("0\n");
			}
		}
		else
		{
			pq.push(val);
		}
	}






	return 0;
}