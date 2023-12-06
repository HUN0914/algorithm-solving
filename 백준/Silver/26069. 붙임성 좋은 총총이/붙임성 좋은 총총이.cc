#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	set<string> s;
	string word1, word2;


	for (int i = 0; i < n; i++)
	{ 
		cin >> word1 >> word2;

		if (word1 == "ChongChong" || word2 == "ChongChong")
		{
			s.insert("ChongChong");
		}

		if (word1 == "ChongChong"||s.find(word1)!=s.end())
		{
			s.insert(word2);
		}
		else if (word2 == "ChongChong"||s.find(word2)!=s.end())
		{
			s.insert(word1);
		}
	}

	cout << s.size();

	return 0;
}