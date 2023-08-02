#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> dp(1000001, 0);

int main(void) {

    int n;
    cin >> n;

    dp[1] = 0;


    for (int i = 2; i <= n; i++)
    {
        if (i % 2 != 0 && i % 3 != 0)
        {
            dp[i] = 1 + dp[i - 1];
        }
        else if (i % 2 == 0 && i % 3 == 0)
        {
            dp[i] = min(1 + dp[i / 2], 1 + dp[i / 3]);
        }
        else if (i % 2 == 0)
        {
            dp[i] = min(1 + dp[i / 2], 1 + dp[i -1]);
        }
        else if (i % 3 == 0)
        {
            dp[i] = min(dp[i / 3] + 1, dp[i - 1] + 1);

        }



    }

    cout << dp[n];





    return 0;
}
