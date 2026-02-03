#include <iostream>

using namespace std;

void ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int abx = x2-x1;
    int aby = y2-y1;
    int bcx = x2-x3;
    int bcy = y2-y3;
    if (abx*bcy-aby*bcx>0){ cout << "-1";}
    else if (abx*bcy-aby*bcx==0){ cout<<"0";}
    else cout<<"1";
}

int main() {
    int x1,x2,y1,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    ccw(x1,y1,x2,y2,x3,y3);
}