#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int>v;

	int n;
	cin >> n;

	if (n == 1)
	{
		int s;
		cin >> s;
		cout << 0;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			int val;
			cin >> val;
			v.push_back(val);
		}
		vector<int>sum;

		int something = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				sum.push_back(-v[i] + v[j]);
			}
		}

		sort(sum.begin(), sum.end(), greater<>());
		cout << sum[0];
	}

	return 0;
}