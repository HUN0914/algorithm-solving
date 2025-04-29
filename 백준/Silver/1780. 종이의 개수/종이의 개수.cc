#include <iostream>

using namespace std;

int checksum[3];
int board[5000][5000];

void checkboardnumber(int start, int end, int size) {
    int value=board[start][end];
    bool isSame=true;

    for (int i=start; i<start+size; i++) {
        for (int j=end; j<end+size; j++) {
            if (board[i][j] !=value) {
                isSame=false;
                break;
            }
        }
        if (!isSame) break;
    }

    if (isSame) {
        checksum[value+1]++;
        return;
    }

    int newSize= size/3;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            checkboardnumber(start+i*newSize, end+j*newSize, newSize);
        }
    }
}


int main(void) {

    int n;
    cin>>n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>board[i][j];
        }
    }
    checkboardnumber(0,0,n);

    for (int i=0; i<3; i++) {
        cout<<checksum[i]<<"\n";
    }
}