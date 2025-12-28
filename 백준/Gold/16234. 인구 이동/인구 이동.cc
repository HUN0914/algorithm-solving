#include <iostream>
#include <queue>

using namespace std;

struct plusLocation {
 int plusY;
 int plusX;
};

struct initLocation {
 int initY;
 int initX;
};

int board[51][51];
int nextBoard[51][51];
int N,L,R;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool isVisited[51][51];
bool isChecked=false;
queue<plusLocation> plusTotal;

void plusValue(int total) {

 while (!plusTotal.empty()) {
  int x=plusTotal.front().plusX;
  int y=plusTotal.front().plusY;
  nextBoard[y][x]=total;
  if (board[y][x] != total)
   isChecked = true;
  plusTotal.pop();
 }

}

void bfs(int i, int j) {

 queue<initLocation>q;
 q.push({i,j});
 isVisited[i][j]=true;
 plusTotal.push({i,j});
 int totalCount=1;
 int totalSum=board[i][j];

 while (!q.empty()) {
  int nx=q.front().initX;
  int ny=q.front().initY;
  q.pop();

  for (int k=0; k<4; k++) {

   int py=ny+dy[k];
   int px=nx+dx[k];

   if (px<0||px>=N||py<0||py>=N) continue;
   if (isVisited[py][px]) continue;
   int value=abs(board[ny][nx]-board[py][px]);
   if (value>=L&&value<=R) {
    plusTotal.push({py,px});
    isVisited[py][px]=true;
    q.push({py,px});
    totalCount++;
    totalSum+=board[py][px];
   }
  }
 }

 if (totalCount>1) {
  int total= totalSum/totalCount;
  plusValue(total);
 }else {
  while (!plusTotal.empty()) plusTotal.pop();
 }

}

int game() {
 int day=0;


 while (true) {
  isChecked=false;

  for (int i=0; i<N; i++) {
   for (int j=0; j<N; j++) {
    isVisited[i][j]=false;
    nextBoard[i][j]=board[i][j];
   }
  }

  for (int i=0; i<N; i++) {
   for (int j=0; j<N; j++) {
    if (isVisited[i][j]) continue;
    bfs(i,j);
   }
  }

  for (int i=0; i<N; i++) {
   for (int j=0; j<N; j++) {
    board[i][j]=nextBoard[i][j];
   }
  }

  if (!isChecked) break ;

  day++;
 }

 return day;
}

int main() {

 cin>>N>>L>>R;

 for (int i=0; i<N; i++) {
  for (int j=0; j<N; j++) {
   cin>>board[i][j];
  }
 }

 cout<<game();

}