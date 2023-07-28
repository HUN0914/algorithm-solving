#include <iostream>

using namespace std;

int main() {
    int binggo[5][5] = { 0, };
    int pannel;
    int count = 0;
    int small_check = 0;
    int five = 0;
    int val = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> binggo[i][j];
        }
    }

    while (small_check < 3) { // 빙고가 3번 이상 외쳐지면 종료
        cin >> pannel;
        count++;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (pannel == binggo[i][j]) {
                    binggo[i][j] = 0;
                }
            }
        }

        small_check = 0; // 빙고 개수를 새로 세기 위해 0으로 초기화

        // 가로 빙고 체크
        for (int i = 0; i < 5; i++) {
            five = 0;
            for (int j = 0; j < 5; j++) {
                if (binggo[i][j] == 0) {
                    five++;
                }
            }
            if (five == 5) {
                small_check++;
            }
        }

        // 세로 빙고 체크
        for (int i = 0; i < 5; i++) {
            five = 0;
            for (int j = 0; j < 5; j++) {
                if (binggo[j][i] == 0) {
                    five++;
                }
            }
            if (five == 5) {
                small_check++;
            }
        }

        // 대각선 빙고 체크
        five = 0;
        for (int i = 0; i < 5; i++) {
            if (binggo[i][i] == 0) {
                five++;
            }
        }
        if (five == 5) {
            small_check++;
        }

        five = 0;
        for (int i = 0; i < 5; i++) {
            if (binggo[i][4 - i] == 0) {
                five++;
            }
        }
        if (five == 5) {
            small_check++;
        }
    }

    cout << count;

    return 0;
}
