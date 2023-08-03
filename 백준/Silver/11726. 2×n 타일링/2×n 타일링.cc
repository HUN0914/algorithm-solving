#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<long long> dp(100001,0);
    int n;

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    if (n == 1)
    {
        cout << dp[1];
    }
    else if (n == 2)
    {
        cout << dp[2];
    }
    else
    {
        for (int i = 3; i <= n; i++)
        {
            dp[i] = ((dp[i - 1] % 10007) + (dp[i - 2] % 10007)) % 10007;
        }

        cout << dp[n];
    }
 


    return 0;
}
