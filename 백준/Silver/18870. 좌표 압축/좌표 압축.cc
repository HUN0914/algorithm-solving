#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

long long result[1000001];
int n;

map<int,int>m;
set<int>s;

int main(void)
{

	cin >> n;
	int val;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		result[i] = val;
		s.insert(val);
		
	}
	std::vector<int> something(s.begin(), s.end());


	for (int i = 0; i < something.size(); i++)
	{
		m.insert({ something[i], i });
	}

	for (int i = 0; i < n; i++)
	{
			printf("%d ", m[result[i]]);

	}


	return 0;
}