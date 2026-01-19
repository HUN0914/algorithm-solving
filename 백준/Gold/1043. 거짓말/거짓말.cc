#include <iostream>
#include <vector>

using namespace std;

int n,m;
int parent[51];

int find(int x) {
    if (parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

void unite(int x, int y) {
    x=find(x);
    y=find(y);
    if (x!=y) parent[y]=x;
}

int main() {
    int count;
    int result=0;
    cin>>n>>m;

    for (int i=1; i<=n; i++) {
        parent[i]=i;
    }
    cin>>count;
    vector<int> truthCount(count);

    for (int i=0; i<count; i++) {
        cin>>truthCount[i];
    }
    for (int i=0; i<count; i++) {
        unite(truthCount[0],truthCount[i]);
    }

    vector<vector<int>> parties(m);
    for (int i=0; i<m; i++) {
        int number;
        cin>>number;
        parties[i].resize(number);
        for (int j=0; j<number; j++) {
            cin>>parties[i][j];
        }
        for (int j=0; j<number; j++) {
            unite(parties[i][0], parties[i][j]);
        }
    }

    if (count==0){
        cout<<m;
    }else {
        for (int i=0; i<m; i++) {
            bool isSame=false;
            for (int j=0; j<parties[i].size(); j++) {
                if (find(parties[i][j])==find(truthCount[0])) {
                    isSame=true;
                    break;
                }
            }
            if (!isSame) result++;
        }
        cout<<result;
    }
}