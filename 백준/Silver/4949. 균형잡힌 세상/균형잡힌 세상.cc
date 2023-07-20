#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    char word[1000];
    vector<char> v;
    char target;

    int count = 0;

    while (1) {
        cin.getline(word, sizeof(word));

        if (strcmp(word, ".") == 0) {
            break;
        } else {
            for (int i = 0; i < strlen(word); i++) {
                if (word[i] == '(' || word[i] == '[') {
                    v.push_back(word[i]);
                } else if (word[i] == ')') {
                    if (!v.empty() && v.back() == '(') {
                        v.pop_back();
                    } else {
                        count++; // 닫는 괄호가 많은 경우를 카운트
                    }
                } else if (word[i] == ']') {
                    if (!v.empty() && v.back() == '[') {
                        v.pop_back();
                    } else {
                        count++; // 닫는 괄호가 많은 경우를 카운트
                    }
                }
            }

            // 괄호가 짝이 맞는지 확인
            if (v.empty() && count == 0) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }

            // 초기화
            v.clear();
            count = 0;
        }
    }

    return 0;
}
