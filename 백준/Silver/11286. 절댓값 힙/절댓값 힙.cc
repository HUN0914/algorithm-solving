#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int x, y;
int t;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void solve()
{
	int val;
	while (t--)
	{
		cin >> val;

		if (val < 0)
		{
			pq.push(make_pair(-val, -1));
		}
		else if (val>0)
		{
			pq.push(make_pair(val, 1));

		}
		else
		{
			if (!pq.empty())
			{
				if (pq.top().second != 1)
				{
					cout << -1*pq.top().first << "\n";
				}
				else
				{
					cout <<  pq.top().first << "\n";
				}
				pq.pop();
			}
			else
			{
				cout << 0 << "\n";
			}
		}
	}
	
}

int main(void)
{
	cin >> t;
	solve();


	//pq.push(make_pair(x, y));

	return 0;
}