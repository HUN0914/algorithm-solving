#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>v;
vector<int>ch;
int n,m;
void dfs(int cnt)
{
	if (cnt == m)
	{
		int counting = 0;
		
		for (int j = 0; j < m-1; j++)
		{
			if (ch[j] <= ch[j + 1])
			{
				counting++;
			}

		}

		if (counting == m - 1)
		{
			for (int i = 0; i < m; i++)
			{
				cout << ch[i] << " ";
			}
			cout << "\n";
			return;
		}

		return;
	}

	for (int j = 0; j < v.size(); j++)
	{
		if (j > 0 && v[j] == v[j - 1]) continue;
		

		ch.push_back(v[j]);

		dfs(cnt + 1);

		ch.pop_back();
	}

}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		v.push_back(val);
	}


	sort(v.begin(), v.end());

	dfs(0);
	

	return 0;
}