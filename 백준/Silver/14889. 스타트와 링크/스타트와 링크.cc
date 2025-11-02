#include <iostream>
#include <vector>
using namespace std;

int N;
int board[21][21];
vector<int> start;
vector<int> link;
bool isChecked[21];

bool isVisitedNumber[21];
int gap=987654321;
int totalStart=0;
int totalLink=0;

void dfsNumber(int cnt, int idx) {
    if (cnt==N/2) {
        link.clear();
        for (int i=1; i<=N; i++) {
            if (!isVisitedNumber[i]) {
                link.push_back(i);
            }
        }
        int totalStart=0;
        int totalLink=0;

        for (int i=0; i<N/2; i++) {
            for (int j=i+1; j<N/2; j++) {
                totalStart+=board[start[i]][start[j]]+board[start[j]][start[i]];
                totalLink+=board[link[i]][link[j]]+board[link[j]][link[i]];
            }
        }
        int  value=(totalStart-totalLink);
        if (value<0) value=-value;
        if (gap>value) gap=value;
    }else {
        for (int i=idx; i<=N; i++) {
            if (isVisitedNumber[i]) continue;
            start.push_back(i);
            isVisitedNumber[i]=true;

            dfsNumber(cnt+1,i+1);
            start.pop_back();
            isVisitedNumber[i]=false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin>>N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin>>board[i][j];
        }
    }
    dfsNumber(0,1);

    cout<<gap;
}