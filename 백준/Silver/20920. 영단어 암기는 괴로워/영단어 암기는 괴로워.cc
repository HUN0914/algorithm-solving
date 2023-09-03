#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool compare(const pair<string, int>&a, const pair<string, int> &b)
{
	if (a.second == b.second)
	{
		if (a.first.length() == b.first.length())
		{
			return a.first < b.first;

		}
		return a.first.length() > b.first.length();

	}
	return a.second > b.second;

}

int main(void){

	int n, m;
	map<string, int> maa;
	map<string, int>::iterator iter;
	string word;


	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> word;
		if (word.size() >= m)
		{
			if (maa.find(word) != maa.end())
			{
				maa[word]++;
			}
			else
			{
				maa.insert({ word, 1 });
			}
		
		}

	}

	vector<std::pair<string,int >> v(maa.begin(), maa.end());

	sort(v.begin(), v.end(), compare);


	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << "\n";
	}


}
