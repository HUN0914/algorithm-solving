#include <bits/stdc++.h>

using namespace  std;

char word[1000001];

int main(void)
{
	int n;
	int length;
	int numbering = 0;
	int counting = 0;
	cin >> n >> length;

	for (int i = 0; i < length; i++)
	{
		cin >> word[i];
	}

	for (int i = 0; i < length; i++)
	{
		if (word[i] == 'O') continue;

		while (word[i + 1] == 'O' && word[i + 2] == 'I')
		{
			numbering++;

			if (numbering == n)
			{
				counting++;
				numbering--;
		//OIOIOIOI 이면 IOI 뒤에 OI가 어떠냐에 따라 추가해줄수도 있으니까//
			}
			i = i + 2;
		}
		numbering = 0;
	
	}

	cout << counting;
	return 0;
}