#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;


int main(void)
{
	vector <string>v;
	vector <string>v1;
	string word;

	cin >> word;

	while (word.size() != 0)
	{
		v.push_back(word);
		word.erase(0, 1);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
		printf("\n");
	}






	return 0;
}