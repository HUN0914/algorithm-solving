#include <iostream>

using namespace std;

int currMap[51][51];
bool isCloud[51][51];
bool isPrevCloud[51][51];
int n,m;
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,-1,-1,-1,0,1,1,1};

int ax[4]={-1,-1,1,1};
int ay[4]={-1,1,-1,1};

void move(int d, int s) {
    
    int dir=d-1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            isPrevCloud[i][j]=false;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (isCloud[i][j]) {
                s=s%n;
                int py=(i+s*dy[dir]+n)%n;
                int px=(j+s*dx[dir]+n)%n;
                isPrevCloud[py][px]=true;
                isCloud[i][j]=false;
            }
        }
    }
}

void rain() {

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (isPrevCloud[i][j]) {
                currMap[i][j]++;
            }
        }
    }
}

void waterCopy() {

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (isPrevCloud[i][j]) {
                int waterCount=0;
                for (int k=0; k<4; k++) {
                    int ny=i+ay[k];
                    int nx=j+ax[k];
                    if (ny>=0&&ny<n&&nx>=0&&nx<n) {
                        if (currMap[ny][nx]>0) waterCount++;
                    }
                }
                currMap[i][j]+=waterCount;
            }
        }
    }


}

void createCloud() {

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!isPrevCloud[i][j]&&currMap[i][j]>=2) {
                isCloud[i][j]=true;
                currMap[i][j]=currMap[i][j]-2;
            }
        }
    }
}

void game(int d, int s) {
    
    move(d,s);
    rain();
    waterCopy();
    createCloud();
}

int main() {

    cin>>n>>m;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) cin>>currMap[i][j];

    for (int i=n-2; i<n; i++)
        for (int j=0; j<2; j++) isCloud[i][j]=true;

    for (int i=0; i<m; i++) {
        int d,s;
        cin>>d>>s;
        game(d,s);
    }

    int result=0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) result+=currMap[i][j];
    
    cout<<result;

        return 0;
}
