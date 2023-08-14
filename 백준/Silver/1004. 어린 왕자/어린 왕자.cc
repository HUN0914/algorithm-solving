#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main(void)
{
	int t;
	int x1, y1, x2, y2;

	int circle;
	int circle_x1, circle_y1, r;
	int count = 0;
	int dou = 0;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		cin >> circle;
		
		for (int j = 0; j < circle; j++)
		{
			cin >> circle_x1 >> circle_y1 >> r;

			if ((((circle_x1 - x1) * (circle_x1 - x1) + (circle_y1 - y1) * (circle_y1 - y1) )< r * r))
			{
				if ((((circle_x1 - x2) * (circle_x1 - x2) + (circle_y1 - y2) * (circle_y1 - y2)) > r * r))
				{
					count++;
					dou++;
				}
			}

			if ((((circle_x1 - x1) * (circle_x1 - x1) + (circle_y1 - y1) * (circle_y1 - y1))> r * r))
			{
				if ((((circle_x1 - x2) * (circle_x1 - x2) + (circle_y1 - y2) * (circle_y1 - y2)) < r * r))
				{
					count++;
					dou++;
				}
			}
			
			dou = 0;

		}
		cout << count << "\n";

		count = 0;
	}


	return 0;
}