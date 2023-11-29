#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{

	int n;
	string word;
	vector<string> v;
	vector<string> down;
	vector<string> up;
	int count = 0;
	int decount = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> word;
		v.push_back(word);
		down.push_back(word);
		up.push_back(word);
	}

	sort(down.begin(), down.end(), greater<>());
	sort(up.begin(), up.end());

	for (int i = 0; i < n; i++)
	{
		if (v[i] == down[i])
		{
			decount++;
		}
		if (v[i] == up[i])
		{
			count++;
		}
	}



	if (count == v.size())
	{
		cout << "INCREASING";
	}
	else if (decount == v.size())
	{
		cout << "DECREASING";
	}
	else
	{
		cout << "NEITHER";
	}


	return 0;
}