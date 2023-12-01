#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int val;
		cin >> val;
		double num_sum = 0;
		double grade_sum = 0;
		
		for (int j = 0; j < val; j++)
		{
			double grade;
			double num;
			cin >>num>>grade;
			num_sum += num;
			grade_sum += grade*num;
		}
		cout << num_sum << " ";
		printf("%.1f", grade_sum/num_sum);
		cout << "\n";

	}


	return 0;
}