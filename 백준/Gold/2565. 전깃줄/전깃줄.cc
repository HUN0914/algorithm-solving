#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct electronic {
    int A;
    int B;
};

bool isMax(electronic &a, electronic & b) {
    if (a.A==b.A) {
        return a.B<b.B;
    }
    return a.A<b.A;
}
int dp[501];
int n;
vector<electronic> line;

int dfs(int i) {
    if (dp[i]!=-1) return dp[i];

    dp[i]=1;
    for (int j=i+1; j<n; j++) {
        if (line[j].B>line[i].B) dp[i]=max(dp[i], 1+dfs(j));
    }
    return dp[i];
}

int main() {
    cin>>n;

    for (int i=0; i<n; i++) {
        int A,B;
        cin>>A>>B;

        line.push_back({A,B});
    }
    memset(dp,-1,sizeof(dp));

    sort(line.begin(), line.end(), isMax);

    int ans=0;
    for (int i=0; i<n; i++) ans=max(ans,dfs(i));

    cout<<n-ans;
}