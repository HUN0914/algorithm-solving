#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	int t;
	int count = 0;
	string word;

	cin >> t;

	for (int i = 0; i<t; i++)
	{
		long long val1, val2;

		cin >> val1 >> val2;

		cout << val1 + val2 << "\n";

	}


	return 0;
}