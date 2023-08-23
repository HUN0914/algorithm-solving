#include <bits/stdc++.h>

using namespace std;

// 입력될 순열
int num[10000] = { 0, };
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    // 순열 입력
    for (int n = 0; n < N; n++)
        cin >> num[n];

    // STL 함수 이용
    // 다음 순열이 존재하면
    // 해당 배열을 다음 순열로 만들고 TRUE 반환
    if (next_permutation(num, num + N))
        for (int i = 0; i < N; i++)
            cout << num[i] << " ";
    else
        cout << -1;

    return 0;
}