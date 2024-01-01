#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	while (1)
	{
		int n;
		cin >> n;

		if (n == 0)
		{
			break;
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 0; j < i; j++)
				{
					cout << "*";
				}
				cout << "\n";
			}

		}

	}
	
	return 0;
}