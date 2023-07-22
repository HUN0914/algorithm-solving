#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
	vector<int> v;
	vector<int>::iterator iter;
	int val;
	int n;
	int money;

	int counting = 0;

	cin >> n >> money;

	for (int i = 0; i < n; i++)
	{
		cin >> val;
		v.push_back(val);
		//if (val > money)
		//{
		//	break;
		//}

	}

	if (n == 1)
	{
		cout << money/val;
	}
	else
	{
		iter = v.end() - 1;

		while (iter != v.begin())
		{
			counting = counting + (money / *iter);
			money = money % (*iter);
			iter--;

		}
		counting = counting + (money / *iter);

		cout << counting;
	}



	return 0;
}