#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int getNewNumber(int num, int p) {
    int result = 0;
    while (num > 0) {
        int digit = num % 10;
        result += pow(digit, p);
        num /= 10;
    }
    return result;
}

int main() {
    int a, p;
    cin >> a >> p;

    vector<int> v;
    v.push_back(a);
    int newNumber = getNewNumber(a, p);

    while (find(v.begin(), v.end(), newNumber) == v.end()) {
        v.push_back(newNumber);
        newNumber = getNewNumber(newNumber, p);
    }

    auto it = find(v.begin(), v.end(), newNumber);
    int index = distance(v.begin(), it);
    cout << index << endl;

    return 0;
}
