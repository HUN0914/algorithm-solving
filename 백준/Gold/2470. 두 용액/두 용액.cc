#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>v;
vector<int> ans(2);

void game() {

    int start=0;
    int end=v.size()-1;
    long min=9987654321;

    while (start<end) {

        if (abs(v[start]+v[end])<min) {
            min=abs(v[start]+v[end]);
            ans[0]=v[start];
            ans[1]=v[end];
        }

        if (v[start]+v[end]>0) {
            end--;
        }else {
            start++;
        }
    }
}

int main() {

    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int val;
        cin>>val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    game();
    sort(ans.begin(),ans.end());

    cout<<ans[0]<<" "<<ans[1];

}