#include <iostream>
#include <queue>
#include <vector> 
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
    vector<string> v;

    string word;
    int n;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        getline(cin, word);
        v.push_back(word);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i+1 << ". " << v[i]<<"\n";
    }

    return 0;
}