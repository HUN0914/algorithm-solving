#include <iostream>
#include <queue>

using namespace std;

struct location {
    int x;
    int y;
};

int n,t;
vector<location> conventionStore;

bool bfs(int startX, int startY, int arriveX, int arriveY) {

    bool isVisitedStore[101]={false};

    queue<location>q;
    q.push({startX,startY});

    while (!q.empty()) {
        int curX=q.front().x;
        int curY=q.front().y;
        q.pop();

        if (abs(arriveX-curX)+abs(arriveY-curY)<=1000) return true;

        for (int i=0; i<conventionStore.size(); i++) {
            if (isVisitedStore[i]) continue;
            int conventionX=conventionStore[i].x;
            int conventionY=conventionStore[i].y;
            if (abs(curX-conventionX)+abs(curY-conventionY)<=1000) {
                isVisitedStore[i]=true;
                q.push({conventionX,conventionY});
            }
        }
    }

    return false;
}

void input() {

    int arriveX;
    int arriveY;
    int startX;
    int startY;

    cin>>t;
    while (t--) {
        cin>>n;
        cin>>startX>>startY;
        conventionStore.clear();
        for (int i=0; i<n; i++) {
            int x,y;
            cin>>x>>y;
            conventionStore.push_back({x+32768,y+32768});
        }
        cin>>arriveX>>arriveY;

        bool isChecked = bfs(startX+32768, startY+32768, arriveX+32768, arriveY+32768);
        if (isChecked) cout<<"happy\n";
        else cout<<"sad\n";
    }

}

int main() {

    input();

    return 0;
}