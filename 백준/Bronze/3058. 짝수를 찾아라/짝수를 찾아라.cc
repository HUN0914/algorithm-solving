#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(void)
{
	int t;
	vector<int>v;
	cin >> t;

	for (int i = 0; i < t; i++)
	{

		int sum = 0;
		int checking = 0;
		int min = 0;
		int val;
		v.clear();
		for (int j = 0; j < 7; j++)
		{
			cin >> val;
			v.push_back(val);
		}
		sort(v.begin(), v.end());

		for (int a = 0; a < 7; a++)
		{
			if (v[a] % 2 == 0)
			{
				if (checking == 0)
				{
					min = v[a];
					checking++;
				}
				sum += v[a];
			}
		}
		printf("%d %d\n", sum, min);
	}


	return 0;
}