#include <iostream>
#include <stack>
#include <vector> 
#include <algorithm>
#include <string>

using namespace std;

long long k, n;


long long binary_search(vector<long long>& v)
{
	long long low = 1;
	long long high = v[0];
	long long idx = -1;
	long long sum = 0;

	while (low <= high)
	{
		sum = 0;
		long long mid = (low + high) / 2;
		for (int i = 0; i < v.size(); i++)
		{
			sum += v[i] / mid;
		}
		if (sum >= n)
		{
			low = mid + 1;
			idx = mid;
			
		}
		//else if (sum > n)
		//{
		//	low = mid + 1;
		//	sum = 0;
		//}
		else if (sum < n)
		{
			high = mid - 1;
		}
		

	}

	return idx;

}


int main(void)
{
	vector<long long>v;
	long long val;
	long long check=0;
	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> val;
		v.push_back(val);
	}
	
	if (k == 1)
	{
		cout << v[0] / n;
	}
	else
	{

			sort(v.begin(), v.end(), greater<>());

			for (int i = 0; i < v.size() - 1; i++)
			{
				if (v[i] == v[i + 1])
				{
					check++;
				}
			}

			if (v[0] == 1)
			{
				cout << n;
			}
			else if (check == v.size() - 1)
			{
				cout << v[0];
			}
			else
			{

				cout << binary_search(v);
			}
	}

	
	return 0;
}