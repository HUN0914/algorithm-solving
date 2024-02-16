#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int t;
	string word;
	cin >> t;

	cin.ignore();

	for(int i=0; i<t; i++)
	{		getline(cin, word);

		word[0] = toupper(word[0]);
		cout << word << "\n";

	}

	return 0;
}