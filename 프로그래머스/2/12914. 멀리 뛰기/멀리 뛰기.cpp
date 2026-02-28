#include <string>
#include <vector>

using namespace std;

long long answer = 0;
vector<int> v;
long long dp[2001];

void dynamic(int n){

    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    
    for(int i=3; i<=n; i++){
        dp[i]=(dp[i-1]+dp[i-2])%1234567;
    }
    
    answer=dp[n];
}

long long solution(int n) {
    dynamic(n);
    return answer;
}