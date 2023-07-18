#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	map<string, string>ma;
	//map<string, string>::iterator iter;
	string word;
	int n, m;

	cin >> n >> m;

	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		//scanf("%[^\n]s", &word);
		getline(cin, word);
		ma.insert(make_pair(word.substr(0, word.find(" ")), word.substr(word.find(" ") + 1, word.length())));
		//v[i].first = word.substr(0, word.find(" "));
		//v[i].second = word.substr(word.find(" ") + 1, word.length());
	}

	for (int i = 0; i < m; i++)
	{
		//scanf("%[^\n]s", &word);
		getline(cin, word);

		if (ma.find(word) != ma.end())
		{
			cout << ma[word];
			cout << endl;
		}
		
	}




	return 0;
}