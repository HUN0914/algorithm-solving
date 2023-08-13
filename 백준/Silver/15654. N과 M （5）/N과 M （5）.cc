#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<int> value;
vector<bool> sel;


void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << value[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (sel[i] == true)
		{
			continue;
		}
		sel[i] = true;
		value.push_back(v[i]);
		dfs(cnt + 1);
		value.pop_back();
		sel[i] = false;
		
	}

}


int main(void)
{
	int val;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> val;
		v.push_back(val);
		sel.push_back(false);
	}

	sort(v.begin(), v.end());



	dfs(0);

	return 0;
}