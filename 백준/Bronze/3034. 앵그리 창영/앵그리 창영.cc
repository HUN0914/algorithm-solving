#include <iostream>

using namespace std;

int main(void)
{
	int t;
	int garo, sero;

	cin >> t;
	cin >> garo >> sero;
	for (int i = 0; i < t; i++)
	{
		int count;
		cin >> count;

		if (count * count <= garo * garo + sero * sero)
		{
			cout << "DA"<<"\n";
		}
		else
		{
			cout << "NE" << '\n';
		}

		
	}


	return 0;
}