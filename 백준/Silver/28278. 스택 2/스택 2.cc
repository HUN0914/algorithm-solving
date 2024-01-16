#define _CRT_SESCURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

stack<int>s;

int main(void)
{
	
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);

		if (n == 1)
		{
			int val;
			scanf("%d", &val);

			s.push(val);
		}
		else if (n == 2)
		{
			if (s.empty())
			{
			//	cout << -1 << "\n";
				printf("-1\n");
			}
			else
			{
				int y = s.top();
				printf("%d\n", y);
				s.pop();


			}
		}
		else if (n == 3)
		{
			if (s.empty())
			{
				cout << 0 << "\n";
			}
			else
			{
				int y1 = s.size();
				printf("%d\n", y1);
				//cout << s.size() << "\n";
			}
		}
		else if (n == 4)
		{
			if (s.empty())
			{
			//	cout << 1 << "\n";
				printf("1\n");
			}
			else
			{
				printf("0\n");
				//cout << 0 << "\n";
			}
		}
		else if (n == 5)
		{
			if (s.empty())
			{
				printf("-1\n");
				//cout << -1 << "\n";
			}
			else
			{
				int y3 = s.top();
				printf("%d\n", y3);
				//cout << s.top() << "\n";
			}
		}


	}

	return 0;
}