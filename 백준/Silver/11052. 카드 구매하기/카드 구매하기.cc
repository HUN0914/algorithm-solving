#include <iostream>

using namespace std;

int n;
int card[1001];
int dp[10001];

void dynamic() {

    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j++) {
            dp[j]=max(card[j],card[j-i]+card[i]);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j++) {
            dp[j]=max(dp[j],dp[j-i]+dp[i]);
        }
    }

    cout<<dp[n];
}

void input() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>card[i];
    }
    dynamic();
}

int main() {
    input();

    return 0;
}