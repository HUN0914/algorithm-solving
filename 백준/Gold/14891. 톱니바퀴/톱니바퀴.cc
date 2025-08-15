#include <iostream>
#include <queue>

using namespace std;

int wheel[4][8];
int new_wheel[4][8];
queue<pair<int,int>> wheel_number_direct;
queue<pair<int,int>>direct_number;

void check_first(int direct) {
    wheel_number_direct.push({0,direct});

    if (wheel[0][2]!=wheel[1][6]) {
        direct=-direct;
        wheel_number_direct.push({1,direct});
        if (wheel[1][2]!=wheel[2][6]) {
            direct=-direct;
            wheel_number_direct.push({2,direct});
            if (wheel[2][2]!=wheel[3][6]) {
                direct=-direct;
                wheel_number_direct.push({3,direct});
            }
        }
    }
}

void check_second(int direct) {
    wheel_number_direct.push({1,direct});

    int dL = -direct;
    if (wheel[1][6]!=wheel[0][2]) {
        wheel_number_direct.push({0,dL});
    }
    int dR = -direct;
    if (wheel[1][2]!=wheel[2][6]) {
        wheel_number_direct.push({2,dR});
        if (wheel[2][2]!=wheel[3][6]) {
            wheel_number_direct.push({3,-dR});
        }
    }
}

void check_third(int direct) {
    wheel_number_direct.push({2,direct});

    int dL = -direct;
    if (wheel[2][2]!=wheel[3][6]) {
        wheel_number_direct.push({3,dL});
    }

    int dR = -direct;
    if (wheel[2][6]!=wheel[1][2]) {
        wheel_number_direct.push({1,dR});
        if (wheel[1][6]!=wheel[0][2]) {
            wheel_number_direct.push({0,-dR});
        }
    }
}

void check_last(int direct) {
    wheel_number_direct.push({3,direct});

    if (wheel[2][2]!=wheel[3][6]) {
        direct=-direct;
        wheel_number_direct.push({2,direct});
        if (wheel[1][2]!=wheel[2][6]) {
            direct=-direct;
            wheel_number_direct.push({1,direct});
            if (wheel[0][2]!=wheel[1][6]) {
                direct=-direct;
                wheel_number_direct.push({0,direct});
            }
        }
    }
}

void game(){

    while (!direct_number.empty()) {

        int number=direct_number.front().first;
        int direct=direct_number.front().second;
        direct_number.pop();

        if (number==1) check_first(direct);
        if (number==2) check_second(direct);
        if (number==3) check_third(direct);
        if (number==4) check_last(direct);

        for (int i=0; i<4; i++) {
            for (int j=0; j<8; j++) {
                new_wheel[i][j]=wheel[i][j];
            }
        }

        while (!wheel_number_direct.empty()) {
            int wheel_number=wheel_number_direct.front().first;
            int direct_last=wheel_number_direct.front().second;
            wheel_number_direct.pop();

            if (direct_last==1) {
                for (int i=0; i<8; i++) {
                   wheel[wheel_number][i]= new_wheel[wheel_number][(i+7)%8];
                }
            }else {
                for (int i=0; i<8; i++) {
                    wheel[wheel_number][i]= new_wheel[wheel_number][(i+1)%8];
                }
            }
        }
    }
}

int sum() {
    int result=0;

    if (wheel[0][0]==1) result+=1;
    if (wheel[1][0]==1) result+=2;
    if (wheel[2][0]==1) result+=4;
    if (wheel[3][0]==1) result+=8;

    return result;
}

int main() {

    int k;
    int number,direct;
    string init_wheel;

    for (int i=0; i<4; i++){
        cin>>init_wheel;
        for (int j=0; j<8; j++) {
            wheel[i][j]=init_wheel[j]-'0';
        }
    }

    cin>>k;
    for (int i=0; i<k; i++) {
        cin>>number>>direct;
        direct_number.push({number,direct});
        game();
    }

    int result_sum=sum();

    cout<<result_sum;

    return 0;
}