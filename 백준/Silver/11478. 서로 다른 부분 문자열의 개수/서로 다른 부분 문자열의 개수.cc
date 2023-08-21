#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>


using namespace std;

set<string>s;

bool sel[1001] = { 0, };




int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string word;

    cin >> word;
    int count = 1;

    for (int i = 0; i < word.size(); i++)
    {
        for (int j = 0; j < word.size(); j++)
        {
            if (j + count <= word.size())
            {
                s.insert(word.substr(j, count));
            }
        }
        count++;

    }

    cout << s.size();



    return 0;
}
