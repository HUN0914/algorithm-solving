#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answerNumber=0;
int answerOrder=0;

vector<int> game(int n, vector<string> words){
    vector<int>total;
    
    vector<string> isPresentString;
    char lastChar;
    
    for(int i=0; i<words.size(); i++){
        string currWord=words[i];
        answerNumber=i%n+1;
        answerOrder=i/n+1;
        
        if(currWord.size()<=1){
            total.push_back(answerNumber);
            total.push_back(answerOrder);
            break;
        }
        if(i>0&&lastChar!=currWord[0]){
            total.push_back(answerNumber);
            total.push_back(answerOrder);
            break;
        }
        
        bool isTrue=false;
        for(auto & keyword : isPresentString){
            if(keyword==currWord){
                isTrue=true;
                total.push_back(answerNumber);
                total.push_back(answerOrder);
                break;
            }
        }
        
        if(isTrue) break;
        isPresentString.push_back(currWord);
        lastChar=currWord[currWord.size()-1];
    }
    
    if(total.empty()){
        total.push_back(0);
        total.push_back(0);
    }
    return total;
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer=game(n,words);
    
    return answer;
}