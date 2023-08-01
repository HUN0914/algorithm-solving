#include <iostream>
 
#define endl "\n"
#define MAX 100010
using namespace std;
 
int N;
int Arr[MAX];
 
int Max(int A, int B) { return A > B ? A : B; }
 
void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> Arr[i];
}
 
void Solution()
{
    int Answer = 1;
    int Len = 1;
    int Len2 = 1;
    for (int i = 1; i < N; i++)
    {
        if (Arr[i] <= Arr[i + 1]) Len++;
        else Len = 1;
 
        if (Arr[i] >= Arr[i + 1]) Len2++;
        else Len2 = 1;
 
        int Result = Max(Len, Len2);
        Answer = Max(Answer, Result);
    } //초기화가 될 경우 큰 값이 날라갈 수도 있으니 항상 answer 변수에 max값을 저장
    cout << Answer << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
