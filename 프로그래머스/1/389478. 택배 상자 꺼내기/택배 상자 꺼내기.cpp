#include <string>
#include <vector>

using namespace std;

int boards[101][11];

int solution(int n, int w, int num) {
    int answer = 0;
    int height = 1;
    int width = 1;
    int total_cnt = 1;

    while (total_cnt <= n) {
        boards[height][width] = total_cnt;

        if (height % 2 == 0) width--;
        else width++;

        if (width == 0 || width == w + 1) {
            height++;
            if (height % 2 == 0) width = w;
            else width = 1;
        }

        total_cnt++;
    }

    int target_y = 0, target_x = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= w; j++) {
            if (boards[i][j] == num) {
                target_y = i;
                target_x = j;
                break;
            }
        }
        if (target_x != 0) break;
    }

    for (int i = target_y; i <= 100; i++) {
        if (boards[i][target_x] != 0) {
            answer++;
        }
    }

    return answer;
}