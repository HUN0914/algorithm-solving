#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number;
int bus;
int INF = 100000000;

vector<pair<int, int>>a[1005];
int d[1005];

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>>pq;

	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		
		int current = pq.top().second;

		int distance = -pq.top().first;

		pq.pop();

		if (d[current] < distance) continue;

		for (int i = 0; i < a[current].size(); i++)
		{
			int next = a[current][i].first;

			int nextdistance = distance + a[current][i].second;

			if (nextdistance < d[next])
			{
				d[next] = nextdistance;
				pq.push(make_pair(-nextdistance, next));
			}
		}

	}
}

int main(void)
{
	int starting;
	int end;
	int pay;
	int last_start;
	int last_end;

	cin >> number >> bus;


	for (int i = 1; i <= number; i++)
	{
		d[i] = INF;
	}

	for (int i = 0; i < bus; i++)
	{
		cin >> starting >> end >> pay;
		a[starting].push_back(make_pair(end, pay));
	}

	cin >> last_start >> last_end;

	dijkstra(last_start);
	
	cout << d[last_end];

	return 0;
}