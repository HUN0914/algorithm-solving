#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(void)
{
	vector<pair<int,int>>v;

	int n;
	int val1;
	int val2;
	int count = 0;


	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> val1 >> val2;
		v.push_back(make_pair(val2, val1));

	}

	sort(v.begin(), v.end());
	
	int value = v[0].first;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].second>= value)
		{
			count++;
			value = v[i].first;
		}

	}

	cout << count+1;


	return 0;
}