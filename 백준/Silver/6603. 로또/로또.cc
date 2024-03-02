#include <bits/stdc++.h>

using namespace std;

int n;
int in[49];
int counting = 0;
bool check[49];

vector<int> out;
void input()
{

	out.clear();
	for (int i = 0; i < n; i++)
	{
		cin >> in[i];
	}
}

void solve(int cnt)
{
	counting = 0;

	if (cnt == 6)
	{
		for (int j = 0; j < out.size()-1; j++)
		{
			if (out[j] < out[j+1])
			{
				counting++;
			}
		}
		
		if (counting == 5)
		{

			for (int i = 0; i < 6; i++)
			{
				cout << out[i] << " ";
			}
			cout << "\n";
		}
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (check[i] == true) continue;
		out.push_back(in[i]);
		solve(cnt + 1);
		check[i] = false;
		out.pop_back();	
	}
	return;
}


int main(void)
{
	ios::sync_with_stdio(false);

	while (1)
	{
		cin >> n;
		if (n == 0) break;
		
		input();
		for (int i = 0; i < n; i++)
		{
			check[i] = false;
		}
		
		solve(0);
		cout << "\n";
		
	}


	return 0;
}