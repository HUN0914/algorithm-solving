#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>


using namespace std;

int main() {

    stack<char> s;
    string word;
    int n;
    int check = 0;
    int count = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> word;

        for (int i = 0; i < word.size(); i++)
        {
            if (s.empty() || s.top() != word[i])
            {
                s.push(word[i]);
            }
            else
            {
                    if (s.top() == word[i])
                    {
                        s.pop();
                    }
                
            }
        }
        if (s.empty())
        {
            count++;
        }
        else
        {
            while (!s.empty())
            {
                s.pop();

            }
            
        }
    }

    printf("%d", count);


    return 0;
}