#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main(void)
{
	vector<int> v;

	int n;
	int val;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		v.push_back(val);
	}

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < n; i++)
	{
		cout << v[i];
		printf("\n");
	}

}