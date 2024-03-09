#include <bits/stdc++.h>

using namespace std;

int n;

void solve(int num)
{
	int size = pow(3, num-1);

	if (num == 0) {
		cout << "-";
		return;
	}

	solve(num - 1);

	for (int i = 0; i < size; i++)
	{
		cout << " ";
	}
	solve(num - 1);


}

int main(void)
{
	while (cin >> n)
	{
		if (n == 0) cout << "-" << "\n";
		
		else
		{
			solve(n);
			cout << "\n";
		}
	}
	

	return 0;
}