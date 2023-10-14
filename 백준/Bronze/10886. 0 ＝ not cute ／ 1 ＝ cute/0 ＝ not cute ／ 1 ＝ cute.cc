#include <iostream>

using namespace std;

int main(void)
{
	int zero = 0;
	int one = 1;

	int v;

	cin >> v;

	for (int i = 0; i < v; i++)
	{
		int val;
		cin >> val;

		if (val == 0)
		{
			zero++;
		}
		else if (val == 1)
		{
			one++;
		}
	}

	if (zero < one)
	{
		cout << "Junhee is cute!";
	}
	else
	{
		cout << "Junhee is not cute!";
	}


	return 0;
}