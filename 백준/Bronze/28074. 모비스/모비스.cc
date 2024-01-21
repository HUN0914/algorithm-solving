#include <iostream>
#include <string>


using namespace std;

int main(void)
{
	string word;
	int m = 0;
	int o = 0;
	int b = 0;
	int i = 0;
	int s = 0;

	cin >> word;

	for (int k = 0; k < word.size(); k++)
	{
		if (word[k] == 'M')
		{
			m++;
		}
		else if (word[k] == 'O')
		{
			o++;
		}
		else if (word[k] == 'B')
		{
			b++;
		}
		else if (word[k] == 'I')
		{
			i++;
		}
		else if (word[k] == 'S')
		{
			s++;
		}

	}
	if (m >= 1 && o >= 1 && b >= 1 && i >= 1 && s >= 1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	return 0;
}