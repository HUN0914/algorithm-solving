#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct val {
    int value;
    int location;
};

stack<val> s;
vector<int>result;
bool isVisited;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    for (int i=1; i<=t; i++) {
        int location=0;
        int val;
        cin>>val;

        while (!s.empty()&&s.top().value<val) s.pop();

        if (!s.empty()) {
            result.push_back(s.top().location);
        }
        else {
            result.push_back(0);
        }
        s.push({val,i});
    }

    for (auto i : result){
        cout<<result[i]<<" ";
    }

}
