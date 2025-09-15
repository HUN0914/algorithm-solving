#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {

    int T;
    cin>>T;

    while (T--) {
        int n,k,t,m;
        cin>>n>>k>>t>>m;
        t--;

        int score[103][103];
        int count[103];
        int last[103];

        memset(score,0,sizeof(score));
        memset(count,0,sizeof(count));
        memset(last,0,sizeof(last));

        vector<pair<pair<int,int>, pair<int,int>>> result;

        for (int time = 1; time <= m; time++) {
            int i, j, s;
            cin >> i >> j >> s;
            i--, j--;
            score[i][j] = max(score[i][j], s);
            count[i]++;
            last[i] = time;
        }

        for (int a=0; a<n; a++) {
            int total=0;
            for (int b=0; b<k; b++) total+=score[a][b];
            result.emplace_back(
                make_pair(-total, count[a]),
                make_pair(last[a], a)
            );
        }
        sort(result.begin(), result.end());

        for (int pos =0; pos<n; pos++) {
            if (result[pos].second.second==t) {
                cout<<pos+1<<"\n";
                break;
            }
        }
    }

    return 0;
}