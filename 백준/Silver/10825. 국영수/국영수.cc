#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <utility>

using namespace std;

bool compare(const tuple<int, int, int, string>& t1, const tuple <int, int, int, string>& t2) {
    //1. 국어 내림차순 2. 영어 오름차순 3. 수학 내림차순 4.이름 오름차순
     //내림 : 큰 값 :true 오름 : 작은 값 true
    if (get<0>(t1) == get<0>(t2)) //국어 같을 때
    {//국어 내림
        if (get<1>(t1) == get<1>(t2)) //영어 같을 때
        {//영어 오름
            if (get<2>(t1) == get<2>(t2)) //수학 같을 때
            {// 이름 올림
                
                return get<3>(t1) < get<3>(t2);
            }

            
            else
            {//수학 내림
                return get<2>(t1) > get<2>(t2);
            }





        }
        else
        {
            //영어 오름
            return get<1>(t1) < get<1>(t2);
        }
        

    }
    //국어 다를 때
    else
    {
        return get<0>(t1) > get<0>(t2); //국어 내림차순
    }




}


int main(void)
{
    int n;
    string name;
    int korean;
    int math;
    int english;

    vector<tuple<int, int, int, string>> v;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> name >> korean >> english >> math;
        v.push_back(make_tuple(korean, english, math, name));
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++)
    {
        cout << get<3>(v[i]);
        printf("\n");
    }

    return 0;
}
