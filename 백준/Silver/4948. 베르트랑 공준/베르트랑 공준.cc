#include <iostream>
#include <algorithm>

using namespace std;

bool arr[246913] = { false };
long long n=1;

long long solve(long long val)
{
	long long count = 0;

	for (long long i = val+1; i <= val*2 ; ++i)
	{
		if (!arr[i]) count++;
	}

	return count;
}

void circle()
{
	arr[0] = true;
	arr[1] = true;

	for (long long i = 2; i * i <= 246912; ++i)
	{
		if (arr[i]) continue;
		for (long long j = 2; j * i <= 246912; ++j)
		{
			arr[i * j] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	circle();
	while (1)
	{
		cin >> n;
		if (n == 0) break;
		else
		{
			cout << solve(n) << "\n";
		}
	}
	return 0;
}