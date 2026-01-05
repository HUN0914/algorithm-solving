#include <iostream>
#include <vector>

using namespace std;

vector<int> p(1000001,-1);

int find(int x) {
    if (p[x]<0) {
        return x;
    }
    return p[x]=find(p[x]);
}

void uni(int u, int v) {
    u = find(u);
    v = find(v);

    if (u==v) return;
    if (p[v]<p[u]) swap (u,v);
    if (p[u]==p[v]) p[u]--;
    p[v]=u;
}

bool finding(int u, int v) {
    u = find(u);
    v = find(v);

    if (u==v) return true;

    return false;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;

    cin>>n>>m;

    for (int i=0; i<m; i++) {
        int one,two,three;

        cin>>one>>two>>three;

        if (one==0){
            uni(two,three);
        }else if (one==1) {
            if (finding(two,three)) {
                cout<<"YES"<<"\n";
            }else {
                cout<<"NO"<<"\n";
            }
        }
    }

    return 0;
}