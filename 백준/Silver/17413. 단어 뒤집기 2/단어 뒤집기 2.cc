#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main(void)
{

	string word;
	stack<char>s;

	getline(cin, word);

	int value = 0;

	while (value != word.size()+1)
	{
		//if (word[value] == ' ' || word[value] == '<'||value==word.size())
		
//		if(value+1!=word.size())
			if (word[value] == '<')
			{
				if (!s.empty())
				{
					while (!s.empty())
					{
						char a = s.top();
						cout << a;
						s.pop();
					}
					cout << "<";
					value++;

				}

					while (word[value] != '>')
					{
						cout << word[value];
						value++;
					}
					cout << ">";
					//value++;
				

			}
			else if (word[value] == ' ')
			{
				while (!s.empty())
				{
					char a = s.top();
					cout << a;
					s.pop();
				}
				cout << " ";
				//value++;
			}
			else if (value == word.size())
			{
				while (!s.empty())
				{
					char a = s.top();
					cout << a;
					s.pop();
				}
				//value++;
			}
		else
		{
			s.push(word[value]);
			//value++;

		}	
			value++;
	}
	

}