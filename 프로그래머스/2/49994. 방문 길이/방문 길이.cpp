#include <string>
#include <vector>

using namespace std;

struct information{
    int prevX;
    int prevY;
    int curX;
    int curY;
};

vector<information> location;
int total=0;

int initX=0;
int initY=0;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

void game(string dirs){

    for(int i=0; i<dirs.size(); i++){
        int px,py;
        if(dirs[i]=='L'){
            if(initX+dx[0]<-5) continue;
            px= initX+dx[0];
            py= initY;
        }else if (dirs[i]=='R'){
            if(initX+dx[1]>5) continue;
            px=initX+dx[1];
            py=initY;
        }else if (dirs[i]=='U'){
            if(initY+dy[2]>5) continue;
            py=initY+dy[2];
            px=initX;
        }else if (dirs[i]=='D'){
            if(initY+dy[3]<-5) continue;
            py=initY+dy[3];
            px=initX;
        }
        
        bool isChecked=true;
        
        for(int i=0; i<location.size(); i++){
            
            if((initX==location[i].prevX&&initY==location[i].prevY)&&
               (px==location[i].curX&&py==location[i].curY)||
               (initX==location[i].curX&&initY==location[i].curY)&&
               (px==location[i].prevX&&py==location[i].prevY)){
                initX=px;
                initY=py;
                isChecked=false;
                break;
            }
        }
        
        if(isChecked){
            location.push_back({initX,initY,px,py});
            initX=px;
            initY=py;
            total++;
        }
    }
}

int solution(string dirs) {
    game(dirs);
    int answer = total;
    return answer;
}