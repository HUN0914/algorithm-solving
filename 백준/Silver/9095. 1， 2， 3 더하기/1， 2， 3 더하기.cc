#include <iostream>
#include <set>
#include <vector>

using namespace std;


int main(void) {

    vector<int> dp(12, 0);

    int n;
    int t;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        for (int i = 4; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        cout << dp[n] << endl;
    }




    return 0;
}
