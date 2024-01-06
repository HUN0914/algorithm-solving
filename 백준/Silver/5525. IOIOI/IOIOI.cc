#include <iostream>
#include <string>

using namespace std;
int i_size = 0;
int o_size = 0;
int counting = 0;


int main(void)
{

	int n;
	int length;
	string word;
	string val;
	cin >> n >> length;

	cin >> word;

	for (int i = 1; i <= length; i++)
	{
		if (n * 2 + i - 1 > length)
		{
			break;
		}

		val = word.substr(i - 1, (n * 2 + 1));

		for (int j = 0; j < val.size(); j++)
		{
			if (j != 0 && j % 2 != 0)
			{
				if (val[j] == 'O')
				{
					o_size++;
				}
			}
			else if (j % 2 == 0)
			{
				if (val[j] == 'I')
				{
					i_size++;
				}
			}
		}

		if (o_size == n && i_size == n + 1)
		{
			counting++;
		}

		o_size = 0;
		i_size = 0;

	}

	cout << counting;
}