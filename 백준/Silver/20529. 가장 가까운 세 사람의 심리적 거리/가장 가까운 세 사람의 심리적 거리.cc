#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

// vector<int>result;
vector<string>str;

string word;
int t;
int n;

int main(void)
{
	ios::sync_with_stdio(false);	
	cin.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int min = 500000;
		int start = 0;

		cin >> n;

			for (int j = 0; j < n; j++)
			{
				cin >> word;
				str.push_back(word);
			}


			if (n > 32)
			{
				cout << 0 << "\n";
			}
			else
			{

				while (start < n)
				{

					int middle = start + 1;
					//int end = middle + 1;
					int sum = 0;

					//if (middle >= n || end >= n)
					//{
					//	break;
					//}

					while (middle < n)
					{
						//middle = start + 1;

						int end = middle + 1;
						while (end < n)
						{

							sum = 0;

							for (int k = 0; k < 4; k++)
							{
								if (str[start][k] != str[middle][k])
								{
									sum++;
								}
								//A,B

								if (str[middle][k] != str[end][k])
								{
									sum++;
								}
								//B,C

								if (str[start][k] != str[end][k])
								{
									sum++;
								}
								//A,C
							}
							if (min > sum)
							{
								min = sum;
							}
							end++;


						}
						middle++;
					}
					start++;
				}
				cout << min << "\n";
			}
			str.clear();


	}

	return 0;
}