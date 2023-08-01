#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    set<int> s;
    vector<int> v;

    int t;
    int n1;
    int n2;
    int val;
    set<int>::iterator iter;

    cin >> t;

    for (int i = 0; i < t; i++)
    {

        cin >> n1;

        for (int i = 0; i < n1; i++)
        {
            cin >> val;
            s.insert(val);
        }

        cin >> n2;

        for (int i = 0; i < n2; i++)
        {
            cin >> val;
            iter = s.find(val);
            if (iter != s.end())
            {
                v.push_back(1);
            }
            else
            {
                v.push_back(0);
            }

        }

        for (int i = 0; i < v.size(); i++)
        {
            printf("%d\n", v[i]);
        }


        //for (int i = 0; i < v.size(); i++)
        //{
        //    iter = s.find(v[i]);
        //    if (iter != s.end())
        //    {
        //        printf("1\n");
        //    }
        //    else
        //    {
        //        printf("0\n");
        //    }


        //}
        s.clear();
        v.clear();

    }

    return 0;
}
