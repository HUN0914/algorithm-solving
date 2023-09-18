#include <iostream>
#include <stack>
#include <vector> 
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{

	int checking = 0;
	int n;
	int val;
	int max;
	vector<int>v;
	stack<int>s;
	vector<char>c;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> val;
		v.push_back(val);

	}

	for (int i = 1; i <= v[0]; i++)
	{
		s.push(i);
		c.push_back('+');
	//	cout << "+" << "\n";
	}
	max = s.top();
	c.push_back('-');
	// cout << "-" << "\n";
	s.pop();

	for (int j = 1; j < v.size(); j++)
	{
		if (checking != 0)
		{
			break;
		}
		if (v[j]>max)
		{
			for (int i = max+1; i <= v[j]; i++)
			{
				s.push(i);
				c.push_back('+');
				//cout << "+" << "\n";
			}
			max = s.top();
			s.pop();
			c.push_back('-');
			//cout << "-" << "\n";

		}
		else
		{

			while (1)
			{
				if (s.empty())
				{
					checking++;
					cout << "NO";
					break;
				}
				if (s.top() == v[j])
				{
					c.push_back('-');
					//cout << "-"<<"\n";
					s.pop();
					break;
				}
				else
				{
					s.pop();
					c.push_back('-');
					//cout << "-" << "\n";
				}
			
			}

		}

	}

	if (checking == 0)
	{
		for (int i = 0; i < c.size(); i++)
		{
			cout << c[i] << "\n";
		}
	}


 }