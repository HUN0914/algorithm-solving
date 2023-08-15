#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int>v;
vector<bool> sel;
vector<int> com;

int n, m;

void dfs(int cnt)
{
	int count = 0;

	if (cnt == m)
	{
		for (int j = 0; j < m - 1; j++)
		{
			if (com[j] <= com[j + 1])
			{
				count++;
			}

			if (count == m - 1)
			{
				for (int k = 0; k < m; k++)
				{
					cout << com[k]<<" ";
				}
				cout << "\n";
			}
		}

		return;

	}

	for (int i = 0; i < n; i++)
	{
		//if (sel[i] == true)
		//{
		//	continue;
		//}

		sel[i] = true;
		com.push_back(v[i]);
		dfs(cnt + 1);
		com.pop_back();
		sel[i] = false;

	}




}

int main(void)
{

	cin >> n >> m;
	int val;

	for (int i = 0; i < n; i++)
	{
		cin >> val;
		v.push_back(val);
		sel.push_back(false);

	}

	sort(v.begin(), v.end());

	if (m == 1)
	{
		for (int i = 0; i < n; i++)
		{
			cout << v[i] << "\n";
		}
	}
	else
	{

		dfs(0);
	}

	return 0;
}