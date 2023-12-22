#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long>v;


long long mid = 0;
long long sum = 0;

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	long long m;

	cin >> t >> m;

	while (t--)
	{
		long long val;
		cin >> val;
		v.push_back(val);
	}
	sort(v.begin(), v.end());

	long long start = 0;
	long long end = v[v.size()-1];
	long long max = -1;

	while (start <= end)
	{
		sum = 0;
		mid = (start + end) / 2;

		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] - mid > 0)
			{
				sum += v[i] - mid;
			}
		}
		//if (sum == m)
		//{
		//	break;
		//} -> 이렇게 되는 경우가 없을 수도 있음.

		if (sum >= m)
		{
			start = mid + 1;
			if (mid > max) max = mid;
			/*
			
			cout mid를 할 시에는 종료될 때의 mid를 담는 거임.
			즉, 마지막에 end=mid-1을 하고 종료가 되더라도
			그때의 mid의 값을 넣어주는 것
			저 if문을 넣어줌으로써 항상 최대의 max 값을 저장함.
			그리고 마지막 반복문에서 어떤 동작이 나오던간에 
			이제까지 저장한 최종의 max값을 저장해준다.
	
			*/
		}
		else
		{
			end = mid - 1;
		}
		
	}

	cout << max;
	return 0;
}