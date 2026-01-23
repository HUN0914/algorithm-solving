#include <iostream>
#include <cstring>

using namespace std;

int n,l;
int testBoard[101][101];
bool used[101];
int result;

void checkWidth() {


    for (int i=0; i<n; i++) {
        bool isChecked=false;
        memset(used,false,sizeof(used));
        for (int j=1; j<n; j++) {
            if (testBoard[i][j-1]!=testBoard[i][j]) { //경사로 오른방향일때
                if (abs(testBoard[i][j-1]-testBoard[i][j])>1) {
                    isChecked=true;
                    break;
                }
                if (testBoard[i][j-1]>testBoard[i][j]) {
                    if (j+l>n){
                        isChecked=true;
                        break;
                    }
                    for (int k=j; k<j+l; k++) {
                        if (testBoard[i][j]!=testBoard[i][k]||used[k]) {
                            isChecked=true;
                            break;
                        }
                    }
                    if (isChecked) break;
                    for (int k=j; k<j+l; k++) used[k]=true;
                        j+=l-1;
                }else {
                    if (j-l<0) {
                        isChecked=true;
                        break;
                    }
                    for (int k=j-1; k>=j-l; k--) {
                        if (testBoard[i][k]!=testBoard[i][j-1]||used[k]) {
                            isChecked=true;
                            break;
                        }
                    }
                    if (isChecked) break;
                    for (int k=j-1; k>=j-l; k--) used[k]=true;
                }
            }
        }
        if (!isChecked) result++;
    }

}

void checkHeight() {

    for (int i=0 ;i<n; i++) used[i]=false;

    for (int i=0; i<n; i++) {
        bool isChecked=false;
        memset(used,false,sizeof(used));
        for (int j=1; j<n; j++) {
            if (testBoard[j-1][i]!=testBoard[j][i]) { //경사로 오른방향일때
                if (abs(testBoard[j-1][i]-testBoard[j][i])>1) {
                    isChecked=true;
                    break;
                }
                if (testBoard[j-1][i]>testBoard[j][i]) {
                    if (j+l>n){
                        isChecked=true;
                        break;
                    }
                    for (int k=j; k<j+l; k++) {
                        if (testBoard[j][i]!=testBoard[k][i]||used[k]) {
                            isChecked=true;
                            break;
                        }
                    }
                    if (isChecked) break;
                    for (int k=j; k<j+l; k++) used[k]=true;
                    j+=l-1;
                }else {
                    if (j-l<0) {
                        isChecked=true;
                        break;
                    }
                    for (int k=j-1; k>=j-l; k--) {
                        if (testBoard[k][i]!=testBoard[j-1][i]||used[k]) {
                            isChecked=true;
                            break;
                        }
                    }
                    if (isChecked) break;
                    for (int k=j-1; k>=j-l; k--) used[k]=true;
                }
            }
        }
        if (!isChecked) result++;
    }
}


void input() {
    cin>>n>>l;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin>>testBoard[i][j];
}

int main() {

    input();
    checkWidth();
    checkHeight();
    cout<<result;

}