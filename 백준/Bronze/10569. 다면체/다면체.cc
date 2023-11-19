#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int val1, val2;
		cin >> val1 >> val2;

		cout << val2 - val1 + 2 << "\n";
	}


	return 0;
}