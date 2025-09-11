#include <iostream>

using namespace std;

int main() {

    string number;
    cin>>number;
    long long start=1;
    long long i=0;

    while (i<number.size()) {
        string startString=to_string(start);

            for (int j=0; j<startString.size(); j++){
                if (startString[j]==number[i]) {
                    i++;
                }
            }
            start++;
    }
    cout<<start-1;
    return 0;
}