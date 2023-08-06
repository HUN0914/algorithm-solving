#define _CRT_SECURE_NO_WARNINGS
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {

	int n;
	int num[10] = { 0, };
	int ten = 10;
	int one = 1;
	int m;
	cin >> n>>m;

	int count = 1;

	while (1)
	{
		if (count > n)
		{
			break;
		}

		if (count < 10)
		{
			num[count] ++;
		}
		else if (count >= 10 && count < 100)
		{
			num[count / 10]++;
			num[count % 10] ++;
			
		}
		else if (count >= 100 && count < 1000)
		{
			num[count / 100] ++;
			num[count % 100 / 10] ++;
			num[count % 10] ++;
		}
		else if (count >= 1000 && count < 10000)
		{
			num[count / 1000] ++;
			num[count % 1000 / 100] ++;
			num[count % 100/10] ++;
			num[count % 10] ++;
		}
		else if (count >= 10000 && count < 100000)
		{
			num[count / 10000] ++;
			num[count % 10000 / 1000] ++;
			num[count % 1000 / 100] ++;
			num[count % 100 / 10] ++;
			num[count % 10] ++;

		}
		else if (count >= 100000 && count < 1000000)
		{
			num[count / 100000]++;
			num[count % 100000 / 10000] ++;
			num[count % 10000 / 1000] ++;
			num[count % 1000 / 100] ++;
			num[count % 100 / 10] ++;
			num[count % 10] ++;
		}

	
		


		count++;
	}

	cout << num[m];



	return 0;

}

