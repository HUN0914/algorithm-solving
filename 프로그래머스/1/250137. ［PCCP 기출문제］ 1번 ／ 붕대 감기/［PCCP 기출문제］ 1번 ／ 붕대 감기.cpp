#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int time_cnt=0;
    int bandage_cnt=0;
    int blood=health;
    bool isAttack=false;
    while(time_cnt<=attacks[attacks.size()-1][0]){
                    
            if(blood>health){
                blood=health;
            }
        
        for(int i=0; i<attacks.size(); i++){
            
            if(time_cnt==attacks[i][0])
            {
                blood-=attacks[i][1];
                bandage_cnt=0;
                isAttack=true;
                
                if(blood<=0){
                return -1;
              }
            }
        }
        
        if(isAttack==true){
            isAttack=false;
        }
        else{
            blood+=bandage[1];
            bandage_cnt++;
            blood = min(blood, health); 
            
            if(bandage_cnt==bandage[0]){
                blood+=bandage[2];
                bandage_cnt=0;
                blood = min(blood, health); 
            }
        }
        
        time_cnt++;

    }
    
    return blood;
}