#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

//'두' 재료의 '고유'한 번호

using namespace std;


int main() {

    int n;
    int m;
    int value;
    vector<int> v;

    int start = 0;
    int end;
    int sum = 0;


    int checking = 0;
    int count = 0;
    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++)
    {

        cin >> value;
        v.push_back(value);
    }

    end = 1;
    sort(v.begin(), v.end());
    sum = v[0] + v[1];

    while (checking<n-1)
    {
       
        sum = v[start] + v[end];
        if (sum == m)
        {
            count++;
        }
        end++;

        if (end == n)
        {
            start++;
            end = start + 1;
            checking++;
        }

    }

   
    
    cout << count;

    return 0;
}