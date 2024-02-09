#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int t;
	string word;
	string result;
	int val;
	int count = 0;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> word;

		for (int i = 2; i < word.size(); i++)
		{
			result += word[i];
		}

		val = stoi(result);
		if (val <= 90) count++;

		result.clear();

		
	}

	cout << count;
	
	return 0;
}