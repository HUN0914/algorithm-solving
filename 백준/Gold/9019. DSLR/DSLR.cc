#include <iostream>
#include <queue>
#include <string>

using namespace std;

bool isVisited[10000];
int num1,num2;

struct dslr {
    int val;
    string s;
};

string bfs() {

    for (int i=0; i<10000; i++) isVisited[i]=false;

    queue<dslr> q;

    q.push({num1,""});
    isVisited[num1]=true;

    while (!q.empty()) {
        int value=q.front().val;
        string s=q.front().s;
        q.pop();

        if (value==num2) {
            return s;
        }

        if (value*2>=10000) {
            //D
            if (!isVisited[(value * 2) % 10000]) {
                q.push({(value * 2) % 10000, s+"D"});
                isVisited[(value*2)%10000]=true;
            }
        } else {
            if (!isVisited[value * 2]) {
                q.push({value * 2, s+"D"});
                isVisited[value * 2]=true;
            }
        }

        if (value-1<0) { //S
            if (!isVisited[9999]) {
                q.push({9999,s+"S"});
                isVisited[9999]=true;
            }
        }else {
            if (!isVisited[value-1]) {
                q.push({value-1,s+"S"});
                isVisited[value-1]=true;
            }
        }

        int L = (value%1000) * 10 + (value/1000);
        if (!isVisited[L]) {
            q.push({L,s+"L"});
            isVisited[L]=true;
        }

        int R = (value%10)*1000 + (value/10);
        if (!isVisited[R]) {
            q.push({R,s+"R"});
            isVisited[R]=true;
        }
    }
}

int main() {

    int t;
    cin>>t;

    for (int i=0; i<t; i++) {
        cin>>num1>>num2;
        string result=bfs();
        cout<<result<<"\n";
    }

    return 0;
}