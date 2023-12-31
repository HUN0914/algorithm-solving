#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{

	int val1, val2, val3;

	cin >> val1 >> val2 >> val3;

	if (val1 + val2 + val3 >= 100)
	{
		cout << "OK";
	}
	else
	{
		if (val1 < val2 && val1 < val3)
		{
			cout << "Soongsil";
		}
		else if (val2 < val1 && val2 < val3)
		{
			cout << "Korea";
		}
		else
		{
			cout << "Hanyang";
		}
	}


	return 0;
}