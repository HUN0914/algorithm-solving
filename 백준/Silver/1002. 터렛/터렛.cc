#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <deque>
#include <map>
#include <string>

using namespace std;



int main(void)
{
	int t;

	double x1, y1, r1, x2, y2, r2;

	double temp;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (r1 < r2)
		{
			temp = r1;
			r1 = r2;
			r2 = temp;

		}

		if (x1 == x2 && y1 == y2)
		{
			if (r1 == r2)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}

		else if ((sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) == r1 + r2)|| (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) == r1 - r2))
		{
			cout << 1 << "\n";
		}
		else if ((sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) < r1 + r2) && (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) > r1 - r2))
		{
			cout << 2 << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}


	}

	return 0;
}