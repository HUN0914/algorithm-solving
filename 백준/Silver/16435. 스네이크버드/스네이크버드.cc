#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	int t;
	int snake;
	int val;
	vector<int>fruit;

	cin >> t >> snake;

	for (int i = 0; i < t; i++)
	{
		cin >> val;
		fruit.push_back(val);
	}

	sort(fruit.begin(), fruit.end());

	for (int i = 0; i < fruit.size(); i++)
	{
		if (snake >= fruit[i])
		{
			snake++;
		}
		else
		{
			break;
		}
	}

	cout << snake;

	return 0;

}

