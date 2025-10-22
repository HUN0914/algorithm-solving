#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct something{
    int totalValue;
    string city;
};

bool isGreater(const something&a, const something& b){
    return a.totalValue<b.totalValue;
}

vector<something>v;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    for(int i=0; i<cities.size();i++){
        if(cacheSize==0){
            return cities.size()*5;
        }
        
        sort(v.begin(),v.end(),isGreater);
        int currentValue=0;
        
        string value=cities[i];
        string lowerWord="";
        
        for(int a=0; a<value.size(); a++){
            lowerWord+=tolower(value[a]);
        }
        
        if(v.size()<cacheSize){
            bool checking=false;
            
            for(int j=0; j<v.size(); j++){
                if(lowerWord==v[j].city){
                    checking=true;
                    currentValue=j;
                    break;
                }
            }
            if(checking){
                answer+=1;
                v[currentValue].totalValue=0;
            }else{
                v.push_back({0,lowerWord});
                answer+=5;
            }            
        }else{ //v.size()가 꽊찻을때
            bool checking=false;
            
            for(int j=0; j<v.size(); j++){
                if(lowerWord==v[j].city){
                    currentValue=j;
                    checking=true;
                }
            }
            if(checking){
                answer+=1;
                v[currentValue].totalValue=0;
            }else{
                if(!v.empty()){
                 v.pop_back();   
                }
                
                v.push_back({0,lowerWord});
                answer+=5;
            }
        }
        
        for(int k=0; k<v.size(); k++){
            v[k].totalValue++;
        }
    }
    
    return answer;
}