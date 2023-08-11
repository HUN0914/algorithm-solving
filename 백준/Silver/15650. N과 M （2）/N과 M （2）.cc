#include <iostream>
#include <vector>

using namespace std;

bool sel[8] = { 0, };

vector<int>v;
int n, m;


void dfs(int cnt)
{
	int count = 0;

	if (cnt == m)
	{
		for (int j = 0; j < m - 1; j++)
		{
			if (v[j] < v[j + 1])
			{
				count++;
			}
		}

		if (count == m - 1)
		{

			for (int i = 0; i < m; i++)
			{
				cout << v[i] << " ";
			}
			count = 0;
			cout << "\n";
		}
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (sel[i] == true)
		{
			continue;
		}

		sel[i] = true;
		v.push_back(i + 1);
		dfs(cnt + 1);
		v.pop_back(); 
		sel[i] = false;
	}

}

int main(void)
{
	cin >> n >> m;

	dfs(0);
}