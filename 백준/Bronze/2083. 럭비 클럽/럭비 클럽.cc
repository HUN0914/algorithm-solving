#include <bits/stdc++.h>

using namespace std;

char word[10];

int main(void)
{

	int age;
	int weight;

	while (1)
	{
		cin >> word >> age>>weight;

		if(strcmp(word,"#") == 0)
		{
			break;
		}
		cout << word<<" ";
		if (age > 17 || weight >= 80)
		{
			cout << "Senior";
		}
		else
		{
			cout << "Junior";
		}

		cout << "\n";

	}


	return 0;
}