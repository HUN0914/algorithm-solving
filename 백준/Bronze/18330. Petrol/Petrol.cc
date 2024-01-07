#include <iostream>

using namespace std;

int main(void)
{
	int n, m;

	cin >> n >> m;

	int sum = 60 + m;

	if (sum > n)
	{
		cout << 1500 * n;
	}
	else
	{
		cout << (1500 * sum) + (3000 * (n-sum));
	}

}