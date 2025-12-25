#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isVisited[16];
vector<string> total_value;
vector<char> alphabet_value;
char init_value[16];

int L;
int C;

void dfs(int cnt,int start) {

    if (cnt==L) {
        string s;
        for (int i=0; i<L; i++) {
            s+=alphabet_value[i];
        }
        total_value.push_back(s);
        return;
    }

    for (int i=start; i<C; i++) {
        if (isVisited[i]) continue;
        alphabet_value.push_back(init_value[i]);
        dfs(cnt+1, i+1);
        alphabet_value.pop_back();
    }
}

void sorting(vector<string>& total_value) {

    for (int i = (int)total_value.size() - 1; i >= 0; i--) {
        int za_count=0;
        int mo_count=0;

        for (int j=0; j<(int)total_value[i].size(); j++) {
            if (total_value[i][j]=='a'
                ||total_value[i][j]=='e'
                ||total_value[i][j]=='i'
                ||total_value[i][j]=='o'
                ||total_value[i][j]=='u'
                ) {
                mo_count++;
            }else {
                za_count++;
            }
        }
        if (mo_count<1||za_count<2) {
            total_value.erase(total_value.begin()+i);
        }
    }

}

int main() {

    cin>>L>>C;

    for (int i=0; i<C; i++) {
        cin>>init_value[i];
    }

    sort(init_value, init_value + C);
    dfs(0,0);
    sorting(total_value);

    for (int j=0; j<(int)total_value.size(); j++) {
        cout<<total_value[j]<<"\n";
    }

}
