#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;


int main(void)
{
	int n, m; // n 끊어짐 , m 브랜드 개수

	vector<int> six;
	vector<int> one;
	int six_val;
	int one_val;
	int min = 0;
	int min1 = 0;

	int combo[3] = { 0, };

	cin >> n >> m;



	for (int i = 0; i < m; i++)
	{
		cin >> six_val;
		cin >> one_val;
		six.push_back(six_val);
		one.push_back(one_val);

	}
	sort(six.begin(), six.end());
	sort(one.begin(), one.end());

	combo[0] = one[0] * n;

	if (n % 6 == 0)
	{
		combo[1] = six[0] * (n / 6);
		combo[2] = six[0] * (n / 6);
	}
	else
	{
		combo[1] = six[0] * ((n / 6) + 1);
		combo[2] = (six[0] * (n / 6)) + (one[0] * (n % 6));

	}

	sort(combo, combo + 3);
	printf("%d", combo[0]);




}