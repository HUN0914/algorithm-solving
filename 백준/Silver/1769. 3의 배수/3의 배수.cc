
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    int count = 0;
    while (int(str.size()) != 1) {
        int sum = 0;
        for (unsigned i = 0; i < str.size(); i++) {
            sum += int(str[i]) - '0';
        }
        str = to_string(sum); //to_string = int형을 string형으로 바꿔주는 것
        count++; 
        /*추가로 백만 자리여도, 백만자리에 다 9를 더해도 int형의 범위를 초과
        하지 않기 때문에, sum에는 각각의 자리에서 나온 값들을 더해도 된다.
        */
    }
    cout << count << '\n';
    if (str == "3" || str == "6" || str == "9")
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
    return 0;
}
