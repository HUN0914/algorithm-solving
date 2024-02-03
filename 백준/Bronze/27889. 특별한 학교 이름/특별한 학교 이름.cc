#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string word;

	cin >> word;

	if (word == "NLCS")
	{
		cout << "North London Collegiate School";
	}
	else if (word == "BHA")
	{
		cout << "Branksome Hall Asia";
	}
	else if (word == "KIS")
	{
		cout << "Korea International School";
	}
	else if (word == "SJA")
	{
		cout << "St. Johnsbury Academy";
	}

	return 0;
}