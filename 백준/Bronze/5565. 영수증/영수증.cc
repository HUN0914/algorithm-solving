#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int result;
	int sum;

	cin >> result;

	for (int i = 0; i < 9; i++)
	{
		cin >> sum;
		result = result - sum;
	}

	cout << result;




	return 0;
}