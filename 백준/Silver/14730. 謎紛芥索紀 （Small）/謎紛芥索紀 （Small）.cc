#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	vector<long long> x;
	vector<long long> num;
	long long result = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int val1, val2;
		cin >> val1 >> val2;
		result = result + val1 * val2;

	}
	cout << result;
	////sort(x.begin(), x.end(), greater<>());
	////sort(num.begin(), num.end(), greater<>());

	//
	//long long result = 0;
	//for (int i = 0; i < n; i++)
	//{
	//	result = result + num[i] * x[i];
	//	
	//}
	//cout << result;


	return 0;
}