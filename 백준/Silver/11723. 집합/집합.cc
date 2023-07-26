#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>



using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    int s = 0;
    int val;
    string word;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> word;
        if (word == "add")
        {
            cin >> val;
            s |= (1 << val); //val의 값을 넣는게 아닌, 그 위치를 넣는것
            
        }
        else if (word == "remove")
        {
            cin >> val;
            s &= ~(1 << val);
            //val의 위치에서 not 연산자를 시켜준 뒤, and 연산을 시켜
            //1이 포함된 위치를 전부 0으로 반환 (not이라 그 위치의 1값은 0)
        }
        else if (word == "check")
        {
            cin >> val;
            if (s & (1 << val))
            {
                printf("1\n");
                
            }
            else
            {
                printf("0\n");
            }

        }
        else if (word == "toggle")
        {
            cin >> val;
            if (s & (1 << val))
            {
                s &= ~(1 << val);
            }
            else
            {
                s |= (1 << val);
            }
          

        }
        else if (word == "all")
        {
            s = (1 << 21) - 1;
            
        }
        else 
        {
            s = 0;
        }

    }
   
    return 0;
}