#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    if (prev_permutation(v.begin(), v.end())) {
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
    }
    else {
   /*     for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }*/
        cout << -1 << "\n";
    }

}