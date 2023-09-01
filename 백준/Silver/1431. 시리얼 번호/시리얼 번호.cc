#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string &a, string &b)
{
	if (a.size() != b.size())
	{
		return a.size() < b.size();
	}
	else
	{
		int gap1 = 0;
		int gap2 = 0;

		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] >= '0' && a[i] <= '9') {
				gap1 += int(a[i]) - 48;
			}

			// 문자열 b에 포함된 숫자들의 합 계산
			if (b[i] >= '0' && b[i] <= '9') {
				gap2 += int(b[i]) - 48;
			}
			
		}
		if (gap1 != gap2)
		{
			return gap1 < gap2;

		}
		else
		{
			return a < b;
		}
		

	}

}


int main()
{
	int n;
	vector<string> v;
	string word;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> word;
		v.push_back(word);
	}

	sort(v.begin(), v.end(), compare);


	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}

}