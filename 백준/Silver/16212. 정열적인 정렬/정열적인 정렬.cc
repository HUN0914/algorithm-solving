#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	vector<int>v;

	int val;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> val;
		v.push_back(val);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		cout << v[i] << " ";
	}


	return 0;
}