#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;



int main() {

    int n;

    cin >> n;

    if (n%7==1||n%7==3)
    {
        cout << "CY";
    }
    else
    {
        cout << "SK";
    }


    return 0;
}