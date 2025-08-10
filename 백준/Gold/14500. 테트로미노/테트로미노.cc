#include <iostream>


using namespace std;

int maximum=0;
int board[1000][1000];
int n,m;
//무조건 좌측 상단을 기준점으로 잡기
//1의 가로
void one_one(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];

    if (x+1<m) {
        sum+=board[y][x+1];
        count++;
    }

    if (x+2<m) {
        sum+=board[y][x+2];
        count++;
    }

    if (x+3<m) {
        sum+=board[y][x+3];
        count++;
    }

    if (sum>maximum&&count==4) maximum=sum;

}

//1의 세로
void one_two(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];

    if (y+1<n) {
        sum+=board[y+1][x];
        count++;
    }

    if (y+2<n) {
        sum+=board[y+2][x];
        count++;
    }

    if (y+3<n) {
        sum+=board[y+3][x];
        count++;
    }

    if (sum>maximum&&count==4) maximum=sum;
}

//2일때 (정사각형)
void two(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];

    if (x+1<m) {
        sum+=board[y][x+1];
        count++;
    }

    if (y+1<n) {
        sum+=board[y+1][x];
        count++;
    }

    if (x+1<m&&y+1<n) {
        sum+=board[y+1][x+1];
        count++;
    }

    if (sum>maximum&&count==4) maximum=sum;
}


//---------3번

void three_one(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];

    if (y+1<n) {
        sum+=board[y+1][x];
        count++;
    }
    if (y+2<n) {
        sum+=board[y+2][x];
        count++;
    }
    if (y+2<n&&x+1<m) {
        sum+=board[y+2][x+1];
        count++;
    }

    if (sum>maximum&&count==4) maximum=sum;
}

//3.2
void three_two(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];
    
    if (y+1<n) {
        sum+=board[y+1][x];
        count++;
    }
    if (y+2<n) {
        sum+=board[y+2][x];
        count++;
    }
    if (y+2<n&&x-1>=0) {
        sum+=board[y+2][x-1];
        count++;
    }

    if (sum>maximum&&count==4) maximum=sum;

}

//3.3
void three_three(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];

    if (x+1<m) {
        sum+=board[y][x+1];
        count++;
    }

    if (y+1<n) {
        sum+=board[y+1][x];
        count++;
    }
    if (y+2<n) {
        sum+=board[y+2][x];
        count++;
    }

    if (sum>maximum&&count==4) maximum=sum;

}

void three_four(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];

    if (x+1<m) {
        sum+=board[y][x+1];
        count++;
    }

    if (y+1<n&&x+1<m) {
        sum+=board[y+1][x+1];
        count++;
    }

    if (y+2<n&&x+1<m) {
        sum+=board[y+2][x+1];
        count++;
    }

    if (sum>maximum&&count==4) maximum=sum;

}

void three_five(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];

    if (y+1<n) {
        sum+=board[y+1][x];
        count++;
    }

    if (x+1<m) {
        sum+=board[y][x+1];
        count++;
    }
    if (x+2<m) {
        sum+=board[y][x+2];
        count++;
    }

    if (sum>maximum&&count==4) maximum=sum;

}

void three_six(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];

    if (x+1<m) {
        sum+=board[y][x+1];
        count++;
    }

    if (x+2<m) {
        sum+=board[y][x+2];
        count++;
    }

    if (x+2<m&&y+1<n) {
        sum+=board[y+1][x+2];
        count++;
    }


    if (sum>maximum&&count==4) maximum=sum;

}

void three_seven(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];

    if (y+1<n) {
        sum+=board[y+1][x];
        count++;
    }

    if (y+1<n&&x+1<m) {
        sum+=board[y+1][x+1];
        count++;
    }

    if (y+1<n&&x+2<m) {
        sum+=board[y+1][x+2];
        count++;
    }

    if (sum>maximum&&count==4) maximum=sum;

}

void three_eight(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];
    if (x+1<m) {
        sum+=board[y][x+1];
        count++;
    }
    if (x+2<m) {
        sum+=board[y][x+2];
        count++;
    }
    if (x+2<m&&y-1>=0) {
        sum+=board[y-1][x+2];
        count++;
    }

    if (sum>maximum&&count==4) maximum=sum;

}


//---- 4번----

void four_one(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];

    if (y+1<n) {
        sum+=board[y+1][x];
        count++;
    }
    if (y+1<n&&x+1<m) {
        sum+=board[y+1][x+1];
        count++;
    }
    if (y+2<n&&x+1<m) {
        sum+=board[y+2][x+1];
        count++;
    }

    if (sum>maximum&&count==4) maximum=sum;

}

void four_two(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];

    if (x+1<m) {
        sum+=board[y][x+1];
        count++;
    }
    if (y+1<n) {
        sum+=board[y+1][x];
        count++;
    }
    if (x+1<m&&y-1>=0) {
        sum+=board[y-1][x+1];
        count++;
    }

    if (sum>maximum&&count==4) maximum=sum;

}

void four_three(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];

    if (x+1<m) {
        sum+=board[y][x+1];
        count++;
    }
    if (x+1<m&&y-1>=0) {
        sum+=board[y-1][x+1];
        count++;
    }
    if (x+2<m&&y-1>=0) {
        sum+=board[y-1][x+2];
        count++;
    }

    if (sum>maximum&&count==4) maximum=sum;

}

void four_four(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];

    if (x+1<m) {
        sum+=board[y][x+1];
        count++;
    }
    if (y+1<n&&x+1<m) {
        sum+=board[y+1][x+1];
        count++;
    }

    if (y+1<n&&x+2<m) {
        sum+=board[y+1][x+2];
        count++;
    }


    if (sum>maximum&&count==4) maximum=sum;

}

//--------5번----
void five_one(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];
    if (x+1<m) {
        sum+=board[y][x+1];
        count++;
    }
    if (y-1>=0&&x+1<m) {
        sum+=board[y-1][x+1];
        count++;
    }
    if (x+2<m) {
        sum+=board[y][x+2];
        count++;
    }

    if (sum>maximum&&count==4) maximum=sum;

}

void five_two(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];

    if (x+1<m) {
        sum+=board[y][x+1];
        count++;
    }
    if (y+1<n&&x+1<m) {
        sum+=board[y+1][x+1];
        count++;
    }
    if (x+2<m) {
        sum+=board[y][x+2];
        count++;
    }


    if (sum>maximum&&count==4) maximum=sum;


}

void five_three(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];

    if (y+1<n) {
        sum+=board[y+1][x];
        count++;
    }
    if (y+2<n) {
        sum+=board[y+2][x];
        count++;
    }
    if (y+1<n&&x+1<m) {
        sum+=board[y+1][x+1];
        count++;
    }

    if (sum>maximum&&count==4) maximum=sum;
}

void five_four(int y, int x) {
    int sum=0;
    int count=1;

    sum=board[y][x];

    if (y+1<n) {
        sum+=board[y+1][x];
        count++;
    }
    if (y+2<n) {
        sum+=board[y+2][x];
        count++;
    }
    if (y+1<n&&x-1>=0) {
        sum+=board[y+1][x-1];
        count++;
    }

    if (sum>maximum&&count==4) maximum=sum;
}

int main(void) {


    cin>>n>>m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>board[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            one_one(i,j);
            one_two(i,j);
            two(i,j);
            three_one(i,j);
            three_two(i,j);
            three_three(i,j);
            three_four(i,j);
            three_five(i,j);
            three_six(i,j);
            three_seven(i,j);
            three_eight(i,j);
            four_one(i,j);
            four_two(i,j);
            four_three(i,j);
            four_four(i,j);
            five_one(i,j);
            five_two(i,j);
            five_three(i,j);
            five_four(i,j);
        }
    }

    cout<<maximum;


    return 0;
}

/*
 *
 *2가지 1가지
 *4가지 4가지 4가지 => 16가지 case로 분류
 *
 *
 *
 */