#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(void) {
    set<string> s;

    int n;
    int count = 0;
    int val = 0;
    string word;

    cin >> n;

    while (count < n) {
        cin >> word;

        if (word == "ENTER") {
            val = val + s.size();
            s.clear();
        }
        else {
            s.insert(word);
        }

        count++;
    }
    val = val + s.size();

    printf("%d", val);
}
