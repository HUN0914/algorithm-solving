#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{

	vector<int>v;

	for (int i = 0; i < 4; i++)
	{
		int val;
		cin >> val;
		v.push_back(val);
	}

	sort(v.begin(), v.end());

	int result = (v[0] + v[3]) - (v[1] + v[2]);
	if (result < 0)
	{
		result = -result;
	}
	cout << result;
	


	return 0;
}