#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int n, m;
vector<int>v;
bool selected[8] = { 0, };
int cnt = 0;

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << v[i] << " ";
			
		}
		cout << "\n";
		return;
	}


	for (int i = 0; i < n; i++)
	{
		if (selected[i] == true)
		{
			continue;
		}
		selected[i] = true;
		v.push_back(i+1);
		dfs(cnt + 1);
		v.pop_back();
		selected[i] = false;

	}

}

int main(void)
{

	cin >> n >> m;





	dfs(0);

	return 0;
}