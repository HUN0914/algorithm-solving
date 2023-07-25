#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


bool cmp(const pair<long long, long long>& a, const pair<long long, long long>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    std::map<long long, long long> m;

    int n;
    long long key;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> key;
        if (m.find(key) != m.end())
        {
            m[key]++;
        }
        else
        {
            m.insert(make_pair(key, 0));
        }


    }
    
    vector<pair<long long, long long>> vec(m.begin(), m.end());

    sort(vec.begin(), vec.end(), cmp);

    cout << vec.begin()->first;

    return 0;
}