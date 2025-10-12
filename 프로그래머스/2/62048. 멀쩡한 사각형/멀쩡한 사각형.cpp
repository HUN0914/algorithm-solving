#include <algorithm>

using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    long long g= __gcd(w,h);
    
    answer=(long long)w*h-(w+h-g);

    return answer;
}