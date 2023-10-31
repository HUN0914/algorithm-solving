#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> v;

	for (int i = 0; i < 3; i++)
	{
		int val;
		cin >> val;
		v.push_back(val);
	}

	sort(v.begin(), v.end());
	if (v[2] == v[1] && v[1] == v[0])
	{
		cout << 2;
	}

	else if (v[2] * v[2] == v[0] * v[0] + v[1] * v[1])
	{
			cout << 1;
	}
	else
	{
		cout << 0;
	}
	


	return 0;
}