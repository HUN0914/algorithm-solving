#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
bool sel[9];
vector<int> chk;
vector<int> v;
int cou;

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << chk[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && v[i] == v[i - 1] && !sel[i - 1])
        { /*
          1 9 1번째로 출력했을 때, sel[i](9가 들어있는 자리)는 sel[i]=true가 될테니
          그 다음 반복문을 돌렸을 때 저 때 sel[i](한 번 돌았으니 sel[i-1]겠지)
          가 true이면 미리 탐색한 것이므로 continue를 한다.
          만약 처음 방문하는 거라면 이 반복문을 사용하지 않는다.
          (전부 sel이 0으로 fallse 되어있으니까)
          그렇기에 테케의 9 9 는 !sel[i-1]는 걸리지 않는다.

          */
            continue;
        }
        if (sel[i] == true)
        {
            continue;
        }
        chk.push_back(v[i]);
        sel[i] = true;
        dfs(cnt + 1);
        chk.pop_back();
        sel[i] = false;
    }
}

int main(void)
{
    cin >> n >> m;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }

    sort(v.begin(), v.end());

    dfs(0);

    return 0;
}
