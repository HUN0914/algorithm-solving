#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(void)
{
	int n;
	int t;

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> t;

		for (int i = 0; i < t; i++)
		{
			cout << "=";
		}
		cout << "\n";
	}
	return 0;
}