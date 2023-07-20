#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

	string word;
	vector<char> v;
	int checking = 0;

	getline(cin, word);


	while (checking < word.size())
	{
		while (checking < word.size())
		{
			if (word[checking]=='U')
			{
				v.push_back('U');
				break;
			}
			else
			{
				checking++;
			}
		}

		while (checking < word.size())
		{
			if (word[checking] == 'C')
			{
				v.push_back('C');
				break;

			}
			else
			{
				checking++;
			}
		}


		while (checking < word.size())
		{
			if (word[checking] == 'P')
			{
				v.push_back('P');
				break;

			}
			else
			{
				checking++;
			}
		}

	
		while (checking < word.size())
		{
			if (word[checking] == 'C')
			{
				v.push_back('C');
				break;

			}
			else
			{
				checking++;
			}
		}

	}

	if (v.size() >= 4)
	{
		printf("I love UCPC");
	}
	else
	{
		printf("I hate UCPC");
	}


}
