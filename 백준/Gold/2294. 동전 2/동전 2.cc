#include <iostream>

using namespace std;

const int INF = 1e9;

int n, k;
int coins[101];
int dp[10001];
int maximum=987654321;

int game(int remain) {

    if (remain==0) return 0;
    if (remain<0) return maximum;

    if (dp[remain]!=-1) return dp[remain];

    int ret=maximum;

    for (int i=0; i<n; i++) {
        int tmp=game(remain-coins[i]);
        if (tmp!=maximum) {
            ret=min(ret,tmp+1);
        }
    }

    dp[remain]=ret;
    return ret;
}

int main() {
    cin>>n>>k;

    for (int i=0; i<n; i++) {
        cin>>coins[i];
    }

    for (int i=0; i<=k; i++) {
        dp[i]=-1;
    }
    int answer=game(k);
    if (answer==maximum) cout<<"-1";
    else cout<<answer;

    return 0;
}