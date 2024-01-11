#include <iostream>

// R : 바위 P : 보 S: 가위
using namespace std;

int game(int n)
{
	char play1;
	char play2;
	int win1 = 0;
	int win2 = 0;

	for (int j = 0; j < n; j++)
	{
		cin >> play1 >> play2;

		if (play1 == 'R')
		{
			if (play2 == 'P') //R<P
			{
				win2++;
			}
			else if (play2 == 'S') 
			{
				win1++;
			}
			// R : 바위 P : 보 S: 가위

		}
		else if (play1 == 'P')
		{
			if (play2 == 'R')
			{
				win1++;
			}
			else if (play2 == 'S')
			{
				win2++;
			}
		}
		else if (play1=='S')//S
		{
			if (play2 == 'R')
			{
				win2++;
			}
			else if (play2 == 'P')
			{
				win1++;
			}
		}

	}

	if (win1 == win2)
	{
		return 0;
	}
	else if (win1 > win2)
	{
		return 1;
	}
	else
	{
		return 2;
	}

}
int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		int result = game(n);

		if (result == 0)
		{
			cout << "TIE" << "\n";
		}
		else if (result == 1)
		{
			cout << "Player 1" << "\n";
		}
		else if (result == 2)
		{
			cout << "Player 2" << "\n";
		}

		
	}


	return 0;
}