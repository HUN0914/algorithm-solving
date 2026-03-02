#include <iostream>
#include <vector>
using namespace std;

int maximum=0;

void dynamic(vector<vector<int>> land){
    int sero=land.size();
    int dp[sero][4];
    
    for(int i=0; i<4; i++){ dp[0][i]=land[0][i]; }
    
    for(int i=1; i<land.size(); i++){
        dp[i][0]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+land[i][0];
        dp[i][1]=max(dp[i-1][0],max(dp[i-1][2],dp[i-1][3]))+land[i][1];
        dp[i][2]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][3]))+land[i][2];
        dp[i][3]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]))+land[i][3];
    }
    
    for(int i=0; i<4; i++){ maximum=max(maximum,dp[sero-1][i]); }
}

int solution(vector<vector<int> > land)
{
    dynamic(land);
    int answer = maximum;

    return answer;
}