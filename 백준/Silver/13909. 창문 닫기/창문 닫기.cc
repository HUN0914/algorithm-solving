#include <iostream>

int main()
{
    int N, count = 0;
    std::cin >> N;
    
    for(int i = 1; i * i <= N; ++i)
        count++;
    std::cout << count;
}

//와.. 짝수일 때, 홀수일 때, 약수는 ex) 2 : 1,2 / 3은 1,3 (2개씩), 4는 제곱수일때
// 1,2,4만 존재. [홀수]-> 즉 홀수번은 열려있단 것 의미