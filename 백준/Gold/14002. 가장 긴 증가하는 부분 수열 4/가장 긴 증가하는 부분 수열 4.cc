#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n;
int dp[1001];
int arr[1001];
vector<int>v;
int length = 0;

void dpp()
{
    for (int i = 1; i <=n; i++)
    {
        dp[i] = 1;
    }

    for (int j = 1; j <= n; j++)
    {
        for (int k = 1; k < j; k++)
        {
            if (arr[j] > arr[k])
            {

                dp[j] = max(dp[j], dp[k] + 1);
            }
        }
        length = max(length, dp[j]);
    }

  

    cout << length << "\n";
    int result = 0;


    for (int j = n; j >= 1; j--)
    {
        if (dp[j] == length)
        {
            v.push_back(arr[j]);
            length--;
        }
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
   

}

int main(void)
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    dpp();

    return 0;
}
