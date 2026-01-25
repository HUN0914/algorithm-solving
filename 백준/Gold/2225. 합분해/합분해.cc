#include <iostream>

using namespace std;
int n,k;
long long dp[201][201];

void dfs(int n, int k) {
    
    for (int i=0; i<=k; i++) {
        dp[0][i]=1;
        dp[1][i]=i;
    }

    for (int i=0; i<=n; i++) {
        dp[i][1]=1;
    }

    for (int i=2; i<=n; i++) {
        for (int j=2; j<=k; j++) {
            dp[i][j]=(dp[i][j-1]+dp[i-1][j])%1000000000;
        }
    }
    cout<<dp[n][k];
}

void input() {
    cin>>n>>k;
    dfs(n,k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
}