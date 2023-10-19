#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int n;
	string word;
	cin >> n;
	cin >> word;

	for (int i = 5; i> 0; i--)
	{
		cout << word[word.size() - i];
	}


	return 0;
}