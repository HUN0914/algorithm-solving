#include <bits/stdc++.h>

using namespace std;

void solve()
{
    list<char> li;
    list<char>::iterator cur = li.begin();
    string word1;

    cin >> word1;

    for (int i = 0; i < word1.size(); i++)
    {
        if (word1[i] == '<')
        {
            if (cur != li.begin())
            {
                cur--;
            }
        }
        else if (word1[i] == '>')
        {
            if (cur != li.end())
            {
                cur++;
            }
        }
        else if (word1[i] == '-')
        {
            if (!li.empty() && cur != li.begin())
            {
                cur = li.erase(--cur);
            }
        }
        else
        {
            li.insert(cur, word1[i]);
   
        }
    }

    for (auto i : li)
    {
        cout << i;
    }
    cout << "\n";
}

int main(void)
{
    int n;
    cin >> n;
  

    while (n--)
    {
        solve();
    }

    return 0;
}
