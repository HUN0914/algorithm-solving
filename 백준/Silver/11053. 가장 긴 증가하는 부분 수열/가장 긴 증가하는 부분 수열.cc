#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    int arr[1001];
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    int dp[1001];
    for (int i = 1; i <= N; i++)
        dp[i] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            /*
            
            솎아내는 과정, 만약에

            10 20 10 30 20 50 이라는 입력이 오면
            p[0]=1이 되고, dp[1]은 max(1, 1+1)을 통해 2가 되고,

            dp[2]는 자신보다 작은 수가 없으므로 1,(반복문에 들어오지 않는다.)
            dp[3]은 max(1,2+1)을 통해 3이된다...
            ->직전 dp에 담긴 값 중에 저 조건만 만족한다면 쭉 반복문을 돌려서
            제일 컸을 때의 dp 값에 +1을 해주는 구조이다.
            */
        }
    }
    sort(dp, dp + N + 1);
    printf("%d", dp[N]);
}