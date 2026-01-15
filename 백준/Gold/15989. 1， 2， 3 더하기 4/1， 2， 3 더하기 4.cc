#include <iostream>

using namespace std;

int dp[10001][4];

void dfs() {

    dp[1][1]=1;
    dp[2][1]=1;
    dp[2][2]=1;
    dp[3][1]=1;
    dp[3][2]=1;
    dp[3][3]=1;

    for (int i=4; i<=10000; i++) {
        dp[i][1]=dp[i-1][1];
        dp[i][2]=dp[i-2][1]+dp[i-2][2];
        dp[i][3]=dp[i-3][1]+dp[i-3][2]+dp[i-3][3];
    }
}

int main() {
    int n;
    int val;
    cin>>n;
    dfs();
    for (int i=0; i<n; i++) {
        cin>>val;
        cout<<dp[val][1]+dp[val][2]+dp[val][3]<<"\n";
    }
}