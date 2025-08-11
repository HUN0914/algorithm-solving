#include <iostream>

using namespace std;

int counting=0;
int boards[51][51];
bool visited[51][51];
int direct_count=0;
int n,m;
int d;
int r,c;

/*
0 : 북쪽
1 : 동쪽
2 : 남쪽
3 : 서쪽
0->3
3->2
2->1
1->0
 */

struct str {
    int r;
    int c;
    int d;
    bool check;
};

str direct_check(int r, int c, int d, bool check) {
    int check_count=0;
    int nd=d;
    int tries=0;

    while (tries<4) {

        nd = (nd + 3) % 4; 

        if (nd == 0) { // 북
            if (r - 1 >= 0 && boards[r - 1][c] == 0) {
                return {r - 1, c, nd, true};
            }
        } else if (nd == 3) { // 서
            if (c - 1 >= 0 && boards[r][c - 1] == 0) {
                return {r, c - 1, nd, true};
            }
        } else if (nd == 2) { // 남
            if (r + 1 < n && boards[r + 1][c] == 0) {
                return {r + 1, c, nd, true};
            }
        } else { // nd == 1 (동)
            if (c + 1 < m && boards[r][c + 1] == 0) {
                return {r, c + 1, nd, true};
            }
        }
        ++tries;
    }

    return {r,c,d,false};

}
int clean(int r, int c, int d, bool check) {

    str result={r,c,d,true};

    while (true) {
        if (boards[r][c]==0) {
            boards[r][c]=2;
            counting++;
        }

        result=direct_check(r,c,d,true);

        if (result.check==true) {
            r=result.r;
            c=result.c;
            d=result.d;
            continue;
        }

        if (result.check==false) {
            if (d==0) { //북
                if (r+1>=n || boards[r+1][c]==1) {
                    return counting;
                }
                r = r+1;
                continue;
            }

            if (d==1) { //동
                if (c-1<0 || boards[r][c-1]==1) {
                    return counting;
                }
                c = c-1;
                continue;
            }

            if (d==2) { //남
                if (r-1<0 || boards[r-1][c]==1) {
                    return counting;
                }
                r = r-1;
                continue;
            }

            if (d==3) { //서
                if (c+1>=m || boards[r][c+1]==1) {
                    return counting;
                }
                c = c+1;
                continue;
            }
        }
    }
}

int main(void){

    cin>>n>>m;
    cin>>r>>c>>d;

    for (int i=0;i<n; i++) {
        for (int j=0;j<m; j++) {
            cin>>boards[i][j];
        }
    }

    cout<<clean(r,c,d,true);

}

/*
 *
 1.현재 칸 청소되지 않은 경우 현재 칸 청소.
 2. 만약 주변 4칸(동서남북) 중 청소되지 않은 빈칸이 없을 때(전부 청소 됐을 때)
 바라보는 방향 유지한 채로 한칸 후진 가능하면 한칸 후진하고 1번으로 돌아감
 뒤쪽이 벽이라 후진할 수 없으면 작동 멈춤
 현재 칸의 주변 4칸 중 청소되지 않은 칸 있을 경우
 반시계 90회전
 바라보는 방향 기준으로 앞쪽 칸 청소 안했을 경우 한칸 전진
 1번으로 돌아감
d
0 : 북쪽
1 : 동쪽
2 : 남쪽
3 : 서쪽
0->3
3->2
2->1
1->0
값이 1이 나오면 작동 멈추고 값 리턴
 *
 *
 *
*/