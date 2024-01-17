#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(void)
{
	bool minus = false;
	string word;
	string num = "";

	int result=0;
	cin >> word;

	for (int i = 0; i <= word.size(); i++)
	{
		if (word[i] == '+' || word[i] == '-' || i == word.size())
		{
			if (minus)
			{
				result -= stoi(num);
			}
			else
			{
				result += stoi(num);
			}
			num = "";

		}
		else
		{
			num += word[i];
		}
		if (word[i] == '-')
		{
			minus = true;
		}

		//1번 -로 다 묶어주기

	}
	cout << result;



	return 0;
}