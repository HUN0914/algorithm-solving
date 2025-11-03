#include <iostream>
#include <algorithm>

using namespace std;

int game(vector<int>&v, int n, int m) {
    int result=0;

    sort(v.begin(),v.end());
    int start=0;
    int end=v[n-1];

    while (start<=end) {
        int sum=0;
        int mid=(start+end)/2;

        for (auto value : v) {
            sum+=min(value,mid);
        }
        if (sum>m) {
            end=mid-1;
        }else {
            result=mid;
            start=mid+1;
        }
    }
    return result;
}

int main() {

    vector<int>v;
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int num;
        cin>>num;
        v.push_back(num);
    }
    int m;
    cin>>m;

    int maximum=game(v,n,m);
    cout<<maximum;

    return 0;
}