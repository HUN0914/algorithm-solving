#include <iostream>

using namespace std;

int main(void)
{
	int x, y;

	cin >> x >> y;

	if (x > y)
	{
		cout << x + y;
	}
	else if (x < y)
	{
		cout << y - x;
	}
	else
	{
		cout << 0;
	}

	return 0;
}