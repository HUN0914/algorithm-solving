#include <iostream>
#include <queue>

using namespace std;

int n,k;
bool visited[220];
int belt[220];
queue<int> robot;
int start;
int ending;
int cnt=0;
int answer=0;

void move_belt() {

    start--;
    ending--;
    if (start<1) start=2*n;
    if (ending<1) ending=2*n;
}


void move_robot() {

    int sizing=robot.size();

    for (int i=0; i<sizing;i++) {
        int curr=robot.front();
        visited[curr]=false;
        robot.pop();

        if (curr==ending) continue;

        int next=curr+1;
        if (next>2*n) next=1;
        if (belt[next] >= 1 && visited[next]==false) {
            belt[next]--;
            if (belt[next]==0) cnt++;
            if (next==ending) continue;
            visited[next]=true;
            robot.push(next);
        }
        else {
            visited[curr]=true;
            robot.push(curr);
        }
    }
}

void make_robot() {

    if (visited[start]==false&& belt[start]>=1) {
        visited[start]=true;
        belt[start]--;
        robot.push(start);

        if (belt[start]==0) cnt++;
    }
}

void solve() {

    start=1;
    ending=n;

    while (cnt<k) {

        answer++;

        move_belt();
        move_robot();
        make_robot();
    }
    cout<<answer;
}

int main() {

    cin>>n>>k;
    for (int i=1; i<=2*n; i++) {
        cin>>belt[i];
    }
    
    solve();

    return 0;
}