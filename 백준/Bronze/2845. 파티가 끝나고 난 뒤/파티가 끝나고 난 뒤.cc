#include <iostream>
#include <vector>


using namespace std;


int main(void)
{
    int n, m;
    int val;
    vector<int>v;
    cin >> n >> m;



    for (int i = 0; i < 5; i++)
    {
        cin >> val;
        v.push_back(val);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << v[i] - (n * m) << " ";
    }

    return 0;

}