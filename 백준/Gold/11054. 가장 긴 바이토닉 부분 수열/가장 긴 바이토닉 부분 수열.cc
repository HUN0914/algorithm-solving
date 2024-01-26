#include <iostream>
#include <algorithm>

using namespace std;

int dp1[1001];
int dp2[1001];
int dp_sum = 0;
int arr[1001];
int n;
int maxing = 0;

void dpp() {
    for (int i = 1; i <= n; i++) {
        dp1[i] = 1;
        dp2[i] = 1; 
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            if (arr[i] > arr[j]) {
                dp2[i] = max(dp2[i], dp2[j] + 1); 
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        dp_sum = dp1[i] + dp2[i];

        if (maxing < dp_sum) {
            maxing = dp_sum;
        }
    }

    cout << maxing-1; //서로 끝에서 중복되니 -1
}

int main(void) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dpp();
    return 0;
}
