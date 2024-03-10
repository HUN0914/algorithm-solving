#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int quad[64][64];
int n;
string s;

void print()
{
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
			quad[i][j] = s[j] - '0';
	}
}

void solve(int y, int x, int size)
{
	int res = quad[y][x];

	for (int i = y; i < y+size; i++)
	{
		for (int j = x; j < x+size; j++)
		{
			if (quad[i][j] != quad[y][x])
			{
				cout << "(";
				solve(y, x, size / 2);
				solve(y,x+size/2, size / 2);
				solve(y + size/2, x, size / 2);
				solve(y + size/2, x + size/2, size / 2);
				cout << ")";
				return;
			}
		}
	}
	cout << res;


}

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	print();
	solve(0, 0, n);

	return 0;

}