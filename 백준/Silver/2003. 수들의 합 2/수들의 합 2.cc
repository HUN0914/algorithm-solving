#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>


using namespace std;


int main() {

    int n;
    int m;
    int element;
    int sum;

    int start = 0;
    int end = 0;

    int count = 0;

    vector<int>v;

    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &element);
        v.push_back(element);
    }

    sum = v[end];

    while (end < n) //기준 값이 끝 값으로 가면 더이상 수행할 필요가 없기 때문
    {
        if (sum < m)
        {
            end++; //값이 작은데 아직 end가 n값까지 안 갔으므로 플러스

            if (end < n) //end가 n보다 큰 값이 되버리면 벡터의 범위 초과
            {//42번째 줄에서 end<n이 된다고 바로 break가 걸리는 것이 아님, if문 연산이 끝나고 걸리는 것.
                sum += v[end];
            }
          
        }
        else if (sum > m)
        { 
            sum -= v[start];
            start++; 
    /*사실 중요한건 end, start는 가리키고, m보다 클 때마다 지워주는 역할을 할 뿐,
    start가 가는 길은 모두 end가 지나간 길이고,
    end가 지난 값을 천천히 따라갈 뿐이다.
    */
        }
        else if (sum == m)
        {
            sum -= v[start];
            start++; //계속 더해지는 값에서, m보다 같아진 경우 뒤에 case는 더 볼 필요 없다. 그렇기에 start++
            end++;//start가 앞으로 땡겨지고, 기존 start 값이 지워지면 무조건 m보다 작음. 다음 연산을 수행해야 하므로 end++
            if (end < n)
            {
                sum += v[end];
            }
            count++;

        }


        
    }

    printf("%d", count);
    return 0;
}