#include <iostream>

using namespace std;

int map[51][51];
bool isCloud[51][51];
bool newCloud[51][51];
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int n,m;

void move(int d, int s) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isCloud[i][j]) {
                int ny = (i + dy[d] * s + n) % n;
                int nx = (j + dx[d] * s + n) % n;
                newCloud[ny][nx] = true;
            }
        }
    }
}

void rain() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (newCloud[i][j]) {
                map[i][j]=map[i][j]+1;
            }
        }
    }
}

void waterCopyBugAndNoCloud() {

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (newCloud[i][j]) {
                if (i-1>=0&&j-1>=0&&map[i-1][j-1]>0) map[i][j]++;
                if (i-1>=0&&j+1<n&&map[i-1][j+1]>0) map[i][j]++;
                if (i+1<n&&j-1>=0&&map[i+1][j-1]>0) map[i][j]++;
                if (i+1<n&&j+1<n&&map[i+1][j+1]>0) map[i][j]++;
            }
        }
    }
}

void newCloudCreate() {

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            isCloud[i][j]=false;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!newCloud[i][j]&&map[i][j]>=2) {
                map[i][j]=map[i][j]-2;
                isCloud[i][j]=true;
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            newCloud[i][j]=false;
        }
    }
}

void game(int d, int s) {
    s%=n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            newCloud[i][j]=false;

    move(d,s);
    rain();
    waterCopyBugAndNoCloud();
    newCloudCreate();
}

int sumResult() {
    int value=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            value+=map[i][j];
        }
    }
    return value;
}

int main() {

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>map[i][j];
        }
    }

    isCloud[n-2][0]=true;
    isCloud[n-2][1]=true;
    isCloud[n-1][0]=true;
    isCloud[n-1][1]=true;

    for (int i=0; i<m; i++) {
        int d,s;
        cin>>d>>s;
        game(d,s);
    }

    int result=sumResult();
    cout<<result;

    return 0;
}