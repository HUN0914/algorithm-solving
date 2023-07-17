#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


int main(void)
{
	char space[100][100] = { 0, };
	int n;
	int counting = 0;
	int garo = 0;
	int sero = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j ++ )
		{

			cin >> space[i][j];
		}
	}

	//°¡·Î
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (space[i][j] == '.')
			{
				counting++;
			}
			else
			{
				if (counting >= 2)
				{
					garo++;
					counting = 0;
				}
				else
				{
					counting = 0;
				}
			}


			

		}
		if (counting >= 2)
		{
			garo++;
		}
		counting = 0;

	}
	counting = 0;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (space[j][i] == '.')
			{
				counting++;
			}
			else
			{
				if (counting >= 2)
				{
					sero++;
					counting = 0;
				}
				else
				{
					counting = 0;
				}
			}




		}
		if (counting >= 2)
		{
			sero++;
		}
		counting = 0;

	}



	cout << garo<<" "<<sero;



	return 0;
}




//if (space[i][j] != space[i][j + 1])
//{
//	if (space[i][j] == '.')
//	{
//		if (counting >= 1)
//		{
//			garo++;
//		}
//	}
//
//}
//else
//{
//	counting++;
//}