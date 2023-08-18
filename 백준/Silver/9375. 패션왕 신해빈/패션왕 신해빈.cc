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

	int n;
	string name;
	string category;
	map<string, int>m;
	map<string, int>::iterator iter;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> name >> category;

			if (m.find(category) != m.end())
			{
				m[category]++;
			}
			else
			{
				m.insert({ category, 1 });
			}


		}
		int ans = 1;

		for(iter=m.begin(); iter!=m.end(); iter++)
		{
			ans *= (iter->second + 1);
		}

		cout << ans - 1<<"\n";
		m.clear();

		

	}

	return 0;
}