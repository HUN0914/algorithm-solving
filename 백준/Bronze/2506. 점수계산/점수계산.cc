#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int t;
	vector<int>v;

	cin >> t;

	int one;
	int sum;
	cin >> one;
	v.push_back(one);
	for (int i = 1; i < t; i++)
	{

		int val;
		cin >> val;
		if (v[i - 1] != 0&&val!=0)
		{
			sum = val + v[i - 1];
		}
		else
		{
			sum = val;
		}
		v.push_back(sum);
	}
	int result = 0;
	for (int i = 0; i < v.size(); i++)
	{
		result += v[i];
	}
	cout << result;

	


	return 0;
}