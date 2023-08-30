#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int m;
bool sel[8] = { 0, };
vector<int>v;
vector<int>choice;

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << choice[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        //if (sel[i] == true)
        //{
        //    continue;
        //}
        sel[i] = true;
        choice.push_back(v[i]);
        dfs(cnt + 1);
        sel[i] = false;
        choice.pop_back();
       
    }



}

int main()
{
    int val;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> val;

        v.push_back(val);

    }
    sort(v.begin(), v.end());
    
    dfs(0);

}