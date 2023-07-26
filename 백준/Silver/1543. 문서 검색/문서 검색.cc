#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>



using namespace std;


int main() {

    string stan, word;

    getline(cin, stan);
    getline(cin, word);

    int ans = 0;

    int wordlen =(int) word.length();

    if (stan.length() < word.length())
    {
        printf("0");
    }
    else
    {
        for (int i = 0; i <= stan.length() - wordlen; i++)
        { //어짜피 저 범위를 넘어가면 wordlen을 받을 수가 없다.
            if (stan[i] == word[0])
            {
                string val = stan.substr(i, wordlen);

                if (val == word) {
                    i += (wordlen - 1);
                    //이 범위만큼 i를 점프해주는 것
                    ans++;

                }
            }

        }
        printf("%d", ans);
    }

    return 0;
}