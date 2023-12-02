#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	char a;
	set<string>s;
	cin >> n >> a;

	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		s.insert(word);
	}

	if (a == 'Y')
	{
		cout << s.size();
	}
	else if (a == 'F')
	{
		cout << s.size() / 2;
	}
	else if (a == 'O')
	{
		cout << s.size() / 3;
	}

	return 0;

}