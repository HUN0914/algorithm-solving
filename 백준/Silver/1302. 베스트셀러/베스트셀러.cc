#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;

    }
    return a.second > b.second;

}


int main() {

    map<string,int> m;
    string word;

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        cin >> word;

        if (m.find(word) != m.end())
        {
            m[word]++;
        }
        else
        {
            m.insert(make_pair(word, 0));
        }
    }

    vector<pair<string, int>>v(m.begin(), m.end());

    sort(v.begin(), v.end(), cmp);

    cout << v.begin()->first;


    return 0;
}