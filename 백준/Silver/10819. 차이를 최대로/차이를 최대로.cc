#include <iostream>
#include <vector>

using namespace std;
vector<int>init;
bool isVisited[9];
int realMax=0;

void dfs(vector<int>& valueTotal) {

    if (valueTotal.size()==init.size()){
        int value=0;
        for (int i=0; i<valueTotal.size()-1; i++) {
            value+=abs(valueTotal[i]-valueTotal[i+1]);
        }
        if (value>realMax) realMax=value;
        return;
    }

    for (int i=0; i<init.size(); i++) {
        if (isVisited[i]) continue;
        isVisited[i]=true;
        valueTotal.push_back(init[i]);
        dfs(valueTotal);
        valueTotal.pop_back();
        isVisited[i]=false;
    }
}

int main() {
    int n;
    cin>>n;

    for (int i=0; i<n; i++) {
        int val;
        cin>>val;
        init.push_back(val);
    }

    vector<int>valueTotal;

    dfs(valueTotal);
    cout<<realMax;
}
