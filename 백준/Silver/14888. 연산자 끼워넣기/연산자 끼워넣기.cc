#include <iostream>
using namespace std;

int N;
int operands[11]; // 수열 
int operators[4]; // 연산자의 개수
int mymin = 1000000001;
int mymax = -1000000001;
void getanswer(int result, int idx)
{
    if (idx == N)
    {
        if (result > mymax)
            mymax = result;
        if (result < mymin)
            mymin = result;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (operators[i] > 0)
        {
            operators[i]--; // 연산자 하나 사용했으므로 1개 줄여줌
            if (i == 0)
                getanswer(result + operands[idx], idx + 1);
            else if (i == 1)
                getanswer(result - operands[idx], idx + 1);
            else if (i == 2)
                getanswer(result * operands[idx], idx + 1);
            else
                getanswer(result / operands[idx], idx + 1);
          operators[i]++; // 다른 연산자를 사용할 것이므로 아까 줄였던 연산자 개수 늘려줌
        
    /*
    
        각 연산에서 return 될 시 원래 getanswer로 돌아온다.
        이때는 idx=n의 직전의 값을 담고 있는 것이므로,
        썼던 operator[i]의 값을 다시 돌려주어야 하므로, operator[i]++을 해주는 것이고
        처음 --는 썼으므로, 다음에 다시 쓰면 안되기 때문에
        (재귀함수에서는 다시 쓸 수도 있다.) 위와 같이 코드를 작성해주는 것이다.

    */
        
        }
    }
    return;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> operands[i];
    for (int i = 0; i < 4; i++)
        cin >> operators[i];
    getanswer(operands[0], 1);
    cout << mymax << '\n';
    cout << mymin;
}