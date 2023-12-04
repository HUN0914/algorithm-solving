#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(void)
{
	int t;
	long long candy;
	long long box;
	long long garo;
	long long sero;
	vector<long long> square;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		long long count = 0;

		cin >> candy >> box;

		for (int j = 0; j < box; j++)
		{
			cin >> garo >> sero;
			square.push_back(garo * sero);
		}

		sort(square.begin(), square.end(), greater<>());

		
		while (candy > 0)
		{
			candy = candy - square[count];
			count++;
		}
		cout << count << "\n";
		square.clear();
	}

	return 0;
}