#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>


using namespace std;


int main(void)
{
	int n;
	string name;
	int year;
	int month;
	int day;

	vector<tuple<int, int, int, string>> v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> name >> day >> month >> year;
		v.push_back(make_tuple(year, month, day, name));

	}

	sort(v.begin(), v.end());
	
	cout << get<3>(v[n - 1]);
	printf("\n");
	cout << get<3>(v[0]);


	
	return 0;
}