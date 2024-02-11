#include <iostream>

using namespace std;

int main(void)
{
	int n;

	int result = 0;

	cin >> n;

	if (n == 1)
	{
		cout << 0;
	}
	else
	{

		for (int i = 1; i < n; i++)
		{
			result += i;
		}

		cout << result;
	}

	return 0;
}