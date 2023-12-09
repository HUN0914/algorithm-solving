#include <iostream>

using namespace std;

int main(void)
{
	int t;

	int val;

	cin >> t;
	while (1)
	{
		cin >> val;
		if (val == 0)
		{
			break;
		}
		
		if (val % t != 0||val==1)
		{
			cout << val << " is NOT a multiple of " << t <<"."<<"\n";
		}
		else
		{
			cout << val << " is a multiple of " << t << "." << "\n";

		}
	

		
	}

	return 0;
}