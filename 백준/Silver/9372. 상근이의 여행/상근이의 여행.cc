#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;


int main(void)
{
	int t;
	int x, y;

	int val1;
	int val2;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> x >> y;
		for (int j = 0; j < y; j++)
		{
			cin >> val1 >> val2;
		}
		cout << x-1;
		printf("\n");

	}


	
	


	return 0;
}