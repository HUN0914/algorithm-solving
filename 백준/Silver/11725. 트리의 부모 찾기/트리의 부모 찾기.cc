#include <bits/stdc++.h>

using namespace std;

vector<int> v[100001];
bool visited[100001];
int t;
int result[100001];

void dfs(int cnt)
{
	visited[cnt] = true;

	for (int i = 0; i < v[cnt].size(); i++)
	{
		int next = v[cnt][i];
		
		if (visited[next] == false)
		{
			//visited[next] = true;
			result[next] = cnt;
			dfs(next);
			
		}
	}
	
}

int main(void)
{
	cin >> t;
	
	int val1, val2;
	for (int i = 0; i < t-1; i++)
	{
		cin >> val1 >> val2;
		
		v[val1].push_back(val2);
		v[val2].push_back(val1);
			
	}

	dfs(1);

	for (int i = 2; i <= t; i++)
	{
		cout << result[i] << "\n";
	}

	return 0;
}