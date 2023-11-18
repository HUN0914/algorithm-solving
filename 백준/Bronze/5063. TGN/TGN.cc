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
		int val1, val2, val3;

		cin >> val1 >> val2 >> val3;

		if (val1 + val3 == val2)
		{
			cout << "does not matter"<<"\n";
		}
		else if (val1 + val3 > val2)
		{
			cout << "do not advertise"<<"\n";
		}
		else
		{
			cout << "advertise"<<"\n";
		}
	}

	return 0;
}