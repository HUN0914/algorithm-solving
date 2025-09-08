#include <iostream>

using namespace std;

int square[1001];
int maximum=0;
int location=0;

int n;

void game() {

    int left_max=0;
    int left=0;
    int right_max=0;
    int right = 0;

    for (int i=1; i<=location; i++) {
        left_max=max(left_max,square[i]);
        left+=left_max;
    }

    for (int i=1000; i>location; i--) {
        right_max=max(right_max,square[i]);
        right+=right_max;
    }

    cout<<left+right;
}

int main() {

    int l,h;
    cin>>n;

    for (int i=0; i<n; i++){
        cin>>l>>h;
        square[l]=h;
        if (h>maximum) {
            location=l;
            maximum=h;
        }
    }
    game();

    return 0;
}