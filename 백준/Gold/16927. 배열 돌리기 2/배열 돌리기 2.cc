#include <iostream>

using namespace std;

int map[301][301];
int N,M,R;

int dr[4]={0,1,0,-1};
int dc[4]={1,0,-1,0};

void rotate(int initY, int initX, int initLocation) {

        int newInitLocation=R%initLocation;

        for (int i=0; i<newInitLocation; i++) {
            int startVal=map[initY][initX];
            int startY= initY;
            int startX= initX;
            int k=0;
            while (k<4) {
                int nr=startY+dr[k];
                int nc=startX+dc[k];

                if (nr==initY&&nc==initX) break;
                if (initY<=nr&&nr<N-initY&&initX<=nc&&nc<M-initX) {
                    map[startY][startX]=map[nr][nc];
                    startY = nr;
                    startX = nc;
                }else {
                    k++;
                }
            }
            map[initY+1][initX]=startVal;
        }
}

int main() {

    cin>>N>>M>>R;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) { cin>>map[i][j]; } }

    int cnt = min(N,M)/2;

    int sizeN=N;
    int sizeM=M;
    for (int i=0; i<cnt; i++) {
        rotate(i,i, 2*sizeN+2*sizeM-4);
        sizeN-=2;
        sizeM-=2;
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) { cout<< map[i][j]<<" "; }
        cout<<"\n";
    }

    return 0;
}