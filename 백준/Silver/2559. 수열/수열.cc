#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> v;

int main(void)
{
    int n, k;
    int val;
    int count = 0;

    int sum = 0;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }

    int start = 0;
    int end = 1;

    sum = v[start];
    vector<long long> dp;

    if (k == 1)
    {
        sort(v.begin(), v.end(), greater<>());
        cout << v[0];
    }
    else
    {

        while (end != n)
        {
            sum += v[end];
            end++;
            count++;

            if (count == k - 1)
            {
                dp.push_back(sum);
                sum -= v[start];
                start++;
                count--;
            }

        }

        // dp.push_back(sum);  // 저장되지 않은 마지막 구간의 합을 저장

        long long max = dp[0];

        for (int i = 0; i < dp.size(); i++)
        {
            //cout << dp[i] << endl;
            if (dp[i] > max)
            {
                max = dp[i];
            }
        }

        cout << max;
    }

    return 0;
}

