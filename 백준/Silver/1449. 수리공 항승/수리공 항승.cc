#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001] = { 0, };



int main() {

    int N,L;
    int val;
    int count = 0;

    cin >> N >> L;

    for (int i = 0; i < N; i++)
    {
        cin >> val;
        dp[val] = -1;
    }

    for (int i = 1; i <= 1000; i++)
    {
        if (dp[i] == -1)
        {
            if (i + L <= 1000)
            {  
                for (int j = i; j < i + L; j++)
                {
                    dp[j] = 1;
                }
                count++;

            }
            else
            {
                for (int j = i; j <= 1000; j++)
                {
                    dp[j] = 1;
                }
                count++;

            }
        }

    }

    cout << count;


    return 0;
}