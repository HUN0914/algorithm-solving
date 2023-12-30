#include <iostream>
#include <algorithm>
using namespace std;
int house[1001][3];
int main() {
    int N;
    int cost[3];
    house[0][0] = 0;
    house[0][1] = 0;
    house[0][2] = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        house[i][0] = min(house[i - 1][1], house[i - 1][2]) + cost[0];
        house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[1];
        house[i][2] = min(house[i - 1][1], house[i - 1][0]) + cost[2];
    }
    cout << min(house[N][2], min(house[N][0], house[N][1]));
}

/*

문제 풀이 접근 방식
: 색을 칠할 때마다의 최소의 경우의 수를 생각해야 한다.
-> 각 색을 칠하기 위해서 전의 최소를 어떻게 구해야 하나? 
--> 지금 칠한 색의 비용+ 이전의 다른 두 색을 칠했을 때의 비용의 최솟값
(맨 처음은 cost만 넣은 값임을 생각하자.)
그렇게 해서 마지막 case에서 특정 색을 기준으로 칠했을 때의 경우의 수 중
가장 작은 경우의 수를 min값으로 출력을 해야한다.

*/
/*

반복문이 돌아갈때마다 house[i][0]~house[i][2]은 갱신되고 그 저장된 값에 따라서
house[i][1],house[i][2],house[i][0]도 갱신됨
맨 처음 house[1][0~2]의 값은 처음 cost의 값

*/