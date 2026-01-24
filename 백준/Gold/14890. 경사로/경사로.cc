#include <iostream>

using namespace std;

int board[101][101];
int n,l;
int result;

void width() {
    for (int i=0; i<n; i++) {
        bool isUsed[101]={false};
        bool isOkay=true;
        for (int j=0; j<n-1; j++) {
            if (abs(board[i][j]-board[i][j+1])>1) isOkay=false;
            if (board[i][j]>board[i][j+1]) {
                if (j+l>=n) {
                    isOkay=false;
                    break;
                }
                for (int k=j+1; k<=j+l; k++) {
                    if (isUsed[k]||board[i][j+1]!=board[i][k]) isOkay=false;
                    isUsed[k]=true;
                }
            }else if (board[i][j]<board[i][j+1]){
                if (j-l+1<0) {
                    isOkay=false;
                    break;
                }
                for (int k=j; k>j-l; k--) {
                    if (isUsed[k]||board[i][j]!=board[i][k]) isOkay=false;
                    isUsed[k]=true;
                }
            }
        }
        if (isOkay) result++;
    }
}

void height() {
    for (int i=0; i<n; i++) {
        bool isUsed[101]={false};
        bool isOkay=true;
        for (int j=0; j<n-1; j++) {
            if (abs(board[j][i]-board[j+1][i])>1) isOkay=false;
            if (board[j][i]>board[j+1][i]) {
                if (j+l>=n) {
                    isOkay=false;
                    break;
                }
                for (int k=j+1; k<=j+l; k++) {
                    if (isUsed[k]||board[j+1][i]!=board[k][i]) isOkay=false;
                    isUsed[k]=true;
                }
            }else if (board[j][i]<board[j+1][i]){
                if (j-l+1<0) {
                    isOkay=false;
                    break;
                }
                for (int k=j; k>j-l; k--) {
                    if (isUsed[k]||board[j][i]!=board[k][i]) isOkay=false;
                    isUsed[k]=true;
                }
            }
        }
        if (isOkay) result++;
    }
}

void input() {
    cin>>n>>l;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>board[i][j];
        }
    }
    width();
    height();
    cout<<result;
}

int main() {
    input();
}