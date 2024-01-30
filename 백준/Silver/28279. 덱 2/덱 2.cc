#include <iostream>
#include <deque>

using namespace std;

deque<int>d;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	int val;
	int some;
	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> val;

		if (val == 1)
		{
			cin >> some;

			d.push_front(some);
		}
		else if (val == 2)
		{
			cin >> some;
			d.push_back(some);
		}
		else if (val == 3)
		{
			if (!d.empty())
			{
				cout << d.front() << "\n";
				d.pop_front();
			}
			else
			{
				cout << -1 << "\n";

			}
		}
		else if (val == 4)
		{
			if (!d.empty())
			{
				cout << d.back() << "\n";
				d.pop_back();
			}
			else
			{
				cout << -1 << "\n";

			}
		}
		else if (val == 5)
		{
			cout << d.size()<<"\n";
		}
		else if (val == 6)
		{
			if (!d.empty())
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << 1 << "\n";
			}
		}
		else if (val == 7)
		{
			if (!d.empty())
			{
				cout << d.front()<<"\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (val == 8)
		{
			if (!d.empty())
			{
				cout << d.back() << "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}

	}

	return 0;
}