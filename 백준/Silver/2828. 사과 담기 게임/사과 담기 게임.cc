#include <iostream>

using namespace std;

int main(void)
{
	int n, m, j;
	int ans = 0;

	cin >> n >> m >> j;

	int left = 1;
	int right = m;


	for (int i = 0; i < j; i++)
	{
		int pos;
		cin >> pos;

		while (pos<left || pos>right)
		{
		
			{
				if (pos < left)
				{
					ans++;
					left--;
					right--;
				}
				if (pos > right)
				{
					ans++;
					left++;
					right++;
				}

			}
		}

	}
	cout << ans << "\n";

	/*
	
	처음 left를 초기 값, right를 바구니의 크기로 잡은 뒤에
	투포인터를 하는 것처럼 범위를 옮겨주면서 만약 left보다 pos가 작으면
	left와 right의 위치를 감소 시켜준다(같이 감소시켜주면 바구니의 크기만큼 감소)

	만약 pos가 right보다 크다면 범주가 뒤에 있는 것이기이에
	left와 right를 투포인터를 움직이는 것처럼 ++로 옮겨준다.
	
	*/
	
}