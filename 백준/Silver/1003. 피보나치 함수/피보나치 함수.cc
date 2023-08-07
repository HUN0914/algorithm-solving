#define _CRT_SECURE_NO_WARNINGS
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;



int main() {

	int t;
	int n;
	int one[100] = { 0, };
	int zero[100] = { 0, };

	cin >> t;
	zero[0] = 1;
	one[1] = 1;

	for (int i = 0; i < t; i++)
	{
		cin >> n;

		if (n == 0)
		{
			cout << "1 0" << "\n";
		}
		else if (n == 1)
		{
			cout << "0 1" << "\n";
		}
		else
		{
			for (int i = 2; i <= n; i++)
			{
				one[i] = one[i - 1] + one[i - 2];
				zero[i] = zero[i - 1] + zero[i - 2];

			}

			cout << zero[n] << " " << one[n] << "\n";
		}
	}



	return 0;

}

