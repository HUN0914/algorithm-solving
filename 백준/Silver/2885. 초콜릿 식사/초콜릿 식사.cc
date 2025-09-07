#include <iostream>

using namespace std;

int k;
int choco=1;
int division=0;

void solve() {

    while (choco<k) {
        choco*=2;
    }

    int tmp=choco;
    int cnt=0;

    while (k!=0) {
        if (k>=tmp) {
            division=cnt;
            k-=tmp;
        }
        tmp=tmp/2;
        cnt++;
    }
}

int main() {

    cin>>k;
    solve();
    cout<<choco<<" "<<division;

    return 0;
}