#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{	string word;


	//char word[52] = { 0, };
	int word_check = 1;
	int word_A = 0;
	int word_dot = 0;
	
	int x_count = 0;

	int checking = 0;


	cin >> word;

	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == 'A')
		{
			word_A++;
		}
		else if (word[i] == '.')
		{
			word_dot++;
		}
		
	}
	//. 문자가 없을 때

	if (word_dot == word.size())
	{
		cout<<word;
		checking++;
	}
	else if (word_dot == 0)
	{
		if (word.size() % 2 != 0)
		{
			printf("-1");
			checking++;
		}
		else
		{

			for (int i = 0; i < (word.size() / 4) * 4; i++)
			{
				word[i] = 'A';
			}

			for (int i = (word.size() / 4) * 4; i < word.size(); i++)
			{
				word[i] = 'B';
			}
			
		}
		//cout << word;
	}
	else
	{
		for (int i = 0; i < word.size(); i++)
		{
			if (word[i] == 'X')
			{
				x_count++;
			}
			if (word[i] != word[i + 1])
			{
					if (x_count % 2 != 0)
					{
						cout << -1;
						checking++;
						break;
					}
					else if (x_count == 4)
					{
						for (int a = 0; a < 4; a++)
						{
							word[i - a] = 'A';
						}
						x_count = 0;

					}
					else if (x_count == 2)
					{
						for (int a = 0; a < 2; a++)
						{
							word[i - a] = 'B';
						}
						x_count = 0;

					}
				
			}


			if (x_count == 4)
			{
				for (int a = 0; a < 4; a++)
				{
					word[i - a] = 'A';
				}
				x_count = 0;

			}
		}

	}

	if (checking == 0)
	{
		cout << word;
	}
	
	return 0;
}