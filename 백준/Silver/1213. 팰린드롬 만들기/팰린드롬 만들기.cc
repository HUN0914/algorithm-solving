#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int alpha[97];
string hol, zzac;
int main()
{
    string s;
    cin >> s;
    for (char i : s)
    {
        alpha[i]++;
    }

    
    for (char i = 'A'; i <= 'Z'; i++)
    { //'A'부터 반복문이 실행되니까 정렬할 필요가 없다.
        //REVERSE 함수를 통해서 /2한 만큼 받은걸 그대로 거꾸로 뒤집어서 출력하면 됨.
        if (alpha[i] % 2)
        {
            hol += i;
        }
        for (int j = 0; j < alpha[i] / 2; j++)
        {
            zzac += i;
        }
    }
    if (hol.size() > 1)
    {
        printf("I'm Sorry Hansoo");
    }
    else
    {
        cout << zzac;
        cout << hol;
        reverse(zzac.begin(), zzac.end());
        cout << zzac;
    }
}