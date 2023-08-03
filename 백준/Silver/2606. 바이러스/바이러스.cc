#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num, pair;
    cin >> num;

    cin >> pair;

    vector<int> dp, first, second;

    if (pair > num)
    {
        dp.resize(pair + 1, 0);
        first.resize(pair + 1, 0);
        second.resize(pair + 1, 0);
    }
    else
    {
        dp.resize(num + 1, 0);
        first.resize(num + 1, 0);
        second.resize(num + 1, 0);
    }




    first[0] = 0;
    second[0] = 0;

    for (int i = 1; i <= pair; i++)
    {
        cin >> first[i] >> second[i];

        if (first[i] == 1)
            dp[second[i]] = 1;
        //if (second[i] == 1)
        //    dp[first[i]] = 1;
    }

    for (int j = 1; j <= pair; j++)
    {

        for (int i = 1; i <= pair; i++)
        {
            if (dp[first[i]] == 1)
            {
                dp[second[i]] = 1;
            }
            if (dp[second[i]] == 1)
            {
                dp[first[i]] = 1;
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= num; i++)
    {
        if (dp[i] == 1)
            count++;
    }

    if (count != 0)
    {
        printf("%d", count - 1);

    }
    else
    {
        printf("0");
    }



    return 0;
}
