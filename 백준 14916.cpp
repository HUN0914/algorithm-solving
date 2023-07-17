#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


int main(void)
{
	int n;
	int five = 0;
	int two = 0;

	cin >> n;

	if (n ==1)
	{
		cout << -1;
	}
	else
	{
		if (n % 10 == 1 || n % 10 == 6)
		{
			cout << 3 + ((n - 6) / 5);
		}
		else if (n % 10 == 2 || n % 10 == 7)
		{
			cout << 1 + ((n - 2) / 5);
		}
		else if (n % 10 == 3 || n % 10 == 8)
		{
			cout << 4 + ((n - 8) / 5);
		}
		else if (n % 10 == 4 || n % 10 == 9)
		{
			cout << 2 + ((n - 4) / 5);
		}
		else
		{
			cout << n / 5;
		}

	}

	return 0;
}