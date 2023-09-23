#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<int>v[1001];
bool visited[1001];

int main(void)
{
	int n, m;
	int temp = 0;

	cin >> n >> m;

	if (n > m)
	{
		temp = n;
		n = m;
		m = temp;
	}//m이더 큼

	if (n == 1)
	{
		cout << m - 1;
	}
	else if (m == 1)
	{
		cout << n - 1;

	}
	else
	{
		cout << (n - 1) + ((m - 1) * n);

	}




	return 0;
}