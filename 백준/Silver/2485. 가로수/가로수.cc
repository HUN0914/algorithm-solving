#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <math.h>
//ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//유클리드 여러번 반복문에서 무한 수행하면 되잖아

using namespace std;

int GCD(int a, int b)
{
	int temp;
	int n;
	if (a < b)
	{
		temp = b;
		b = a;
		a = temp;

	}
	while (b != 0)
	{
		n = a % b;
		a = b;
		b = n;
	}

	return a;
}

int main() {
	int gap = 0;
	int n;
	vector<int> v;
	vector<int> cha;
	int count=0;
	int val;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		v.push_back(val);
	}

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < v.size() - 1; i++)
	{
		val = v[i] - v[i + 1];
		cha.push_back(val);
	}

	for (int i = 0; i < cha.size()-1; i++)
	{
		gap = GCD(cha[i], cha[i + 1]);
		
	}

	int k = v[v.size() - 1];

	while (1)
	{
		if (k > v[0])
		{
			break;
		}
		k += gap;
		count++;
	}
	// cout << count << endl;

	count = count - v.size();

	printf("%d", count);




	

	



}

 