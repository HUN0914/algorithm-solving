#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

\
int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> v;

    int n;
    int val;
    int goal;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);

    }
    sort(v.begin(), v.end());
    cin >> goal;

    int start = 0;
    int end = n-1;
    int count = 0;

    int sum = 0;
    //11을 받았을 때를 카운팅 못하는 중
    //서로 다른 입니다..... st에서 catch하면 넘어가도 돼요


    while (start!=end)
    {
        sum = v[start] + v[end];

        if (sum == goal)
        {
          /*  sum -= v[start];*/
            start++;
            count++;
        }

        if (sum > goal)
        {
            end--;
        }

        if (sum < goal)
        {
            start++;
        }
        
    }

    cout << count;

    return 0;
}
