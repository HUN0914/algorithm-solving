#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <deque>


using namespace std;

int main(void)
{
	deque<int>q;
	vector<int>v;
	deque<int>::iterator iter;
	int val;

	int grade = 0;
	int count = 0;
	int checking = 0;

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		q.push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> val;
		v.push_back(val);
	}

	while (1)
	{
		if (grade==m)
		{
			break;
		}

		if (q.front() == v[grade])
		{
			q.pop_front();
			grade++;
			
		}
		else
		{

			int targetNumber = v[grade];
			auto it = std::find(q.begin(), q.end(), targetNumber);

			int position = distance(q.begin(), it);

			if (position < (q.size()/2) + 1)
			{
				while(1)
				{
					if (q.front() == v[grade])
					{
						break;
					}
					q.push_back(q.front());
					q.pop_front();
					count++;
				}
			}
			else
			{
				while (1)
				{
					if (q.front() == v[grade])
					{
						break;
					}
					q.push_front(q.back());
					q.pop_back();
					count++;
				}

			}

		}


	}
	cout << count;

	return 0;
}