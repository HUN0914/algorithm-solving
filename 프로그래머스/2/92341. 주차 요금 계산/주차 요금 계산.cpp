#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, int> recordsCount;
    map<string, string> recordsTime;
    
    for(int i=0; i<records.size(); i++){
        string timer;
        string name;
        string isCome;
        stringstream ss(records[i]);
        ss>>timer>>name>>isCome;
        
        if(isCome=="IN"){
            recordsTime[name]=timer;
        }
        else if (isCome=="OUT"){
            string recordsTimer=recordsTime[name];
            string outStr= timer;
            
            int inH = stoi(recordsTimer.substr(0,2));
            int inM = stoi(recordsTimer.substr(3,2));
            
            int outH = stoi(outStr.substr(0,2));
            int outM = stoi(outStr.substr(3,2));
            
             int total=(outH*60+outM)-(inH*60+inM);
            recordsCount[name]+=total;
            recordsTime[name]="-1";
        }
        
    }
    
    for(auto & t :recordsTime){
        if(t.second!="-1"){
            string inStr=t.second;
            string inH=inStr.substr(0,2);
            string inM=inStr.substr(3,2);
            
            int value=(23*60+59)-(stoi(inH)*60+stoi(inM));
            recordsCount[t.first]+=value;
        }
    }

    for(auto & m :recordsCount){
        if(m.second<=fees[0]){
            answer.push_back(fees[1]);
        }else{
            int rest = m.second-fees[0];
            int unit = rest/fees[2];
            if(rest%fees[2]!=0) unit++;
            int total = fees[1] + unit * fees[3];  
            answer.push_back(total);
        }
    }
    
    return answer;
}
