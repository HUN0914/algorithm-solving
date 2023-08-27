#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	string word;

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> word;

		for (int i = 0; i < word.size(); i++)
		{
			word[i]=tolower(word[i]);
		}
		cout << word << "\n";
	}
	

	return 0;
}