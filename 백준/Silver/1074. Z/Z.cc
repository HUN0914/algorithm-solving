#include <iostream>
#include <cmath>
using namespace std;
int n, r, c;
int ans = 0;
void dc(int x, int y, int size) {
    if (c == x && r == y) { // 찾으려는 열과 행이 일치하면 
        cout << ans;
        return;
    }
    else if (c < x + size && r < y + size && c >= x && r >= y) {
        //찾으려는 열과 행이 4분면안에 있을 경우
        dc(x, y, size / 2);
        /*
        처음에 쭉 나눠준다. 그래서 위 조건에 부합할 시
        특히 이 첫번째 조건은 맨 처음 섹터를 나눠주는 역할도 한다.
        즉, 계속 나눴을 때의 섹터에 없을 경우에는 그 위치에 
        size*size를 해주는 것이다.
        */
        dc(x + size / 2, y, size / 2); //1

        /*
        
        위 조건에서도 부합하지 않을 시(특히 여기서 저 조건에 부합하지 않아서
        size*size를 했을 때 그 때의 size를 계속 안고 가는 것이다.
        우측을 탐색했을 때 없을 시에는 다음 단계로 넘긴다.
        
        */
        dc(x, y + size / 2, size / 2); //2
        
        /*
        위 조건에서 x는 x+size의 값을 의미한다.
        
        */
        
        dc(x + size / 2, y + size / 2, size / 2);

        /*
        왼-왼쪽 옆
        아래- 아래쪽 옆 이 순서가 있기 때문에 함수의 순서가
        매우 중요하다. 

        */
    }
    else { // 없다면 숫자 카운트 -> 정사각형 넓이
        ans += size * size;
    }

    /*
    처음에는 전체적인 위치를 잡아줌 (0,0 시작)
    그렇게 최소 조건으로 다 빼주고, 거기서 왼-오-아래왼-아래오 나누기
    (1)일 때 (오른쪽일 때) 다시 처음부터 재귀를 시작해
    /2를 통하여 제일 왼쪽에 있는 값을 구해줌.

    */
}
int main() {
    cin >> n >> r >> c;
    dc(0, 0, pow(2, n));
    return 0;
}
