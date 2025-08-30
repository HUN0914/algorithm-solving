#include <iostream>

using namespace std;

int n;
int day[16];
int cost[16];
int answer;

void dfs(int cur_day, int total_cost) {

    if (cur_day>=n+1) {
        answer=max(answer,total_cost);
        return;
    }

    if (cur_day+day[cur_day]<=n+1) dfs(cur_day+day[cur_day], total_cost+cost[cur_day]);
    if (cur_day+1<=n+1) dfs(cur_day+1, total_cost);
}

int main() {

    cin>>n;

    for (int i=1; i<=n; i++) {
        cin>>day[i]>>cost[i];
    }

    dfs(1,0);
    cout<<answer;

    return 0;
}
