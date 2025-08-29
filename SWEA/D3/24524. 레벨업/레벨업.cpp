#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        long long X[55];
        for (int i = 1; i <= N; i++) cin >> X[i];

        long long base = 0;
        for (int i = 1; i < N; i++) {
            base += abs(X[i+1] - X[i]);
        }

        long long best_save = 0;
        for (int k = 2; k <= N-1; k++) {
            long long a = abs(X[k] - X[k-1]);
            long long b = abs(X[k+1] - X[k]);
            long long c = abs(X[k+1] - X[k-1]);
            long long save = a + b - c;
            if (save > best_save) best_save = save;
        }

        cout << (base - best_save) << "\n";
    }
    return 0;
}