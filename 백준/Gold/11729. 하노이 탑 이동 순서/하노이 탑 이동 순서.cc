#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


void hanoi(int n, int start, int by, int end)
{
	if (n == 1)
	{
		cout << start << " " << end << "\n";
		return;
	}
	else
	{
		hanoi(n - 1, start, end, by);
		cout << start << " " << end << "\n";
		hanoi(n - 1, by, start, end);
	}


}


int main(void)
{
	int n;
	cin >> n;

	int k = pow(2, n) - 1;
	cout << k << "\n";
	hanoi(n, 1, 2, 3);

	return 0;
}

//아오  ㅅㅂ