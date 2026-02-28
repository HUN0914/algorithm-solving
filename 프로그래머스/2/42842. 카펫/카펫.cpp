#include <string>
#include <vector>
#include <cmath>

using namespace std;
vector<int> answer;

void checkMax(int sero, int garo, int brown){
    if(2*(garo+sero)+4==brown){
        answer.push_back(garo+2);
        answer.push_back(sero+2);
        return;
    }
}

void checking(int brown, int yellow){
    for(int i=1; i<=sqrt(yellow); i++){
        if(yellow%i==0){
            checkMax(i, yellow/i, brown);
        }
    }
}

vector<int> solution(int brown, int yellow) {
    
    checking(brown,yellow);
    
    return answer;
}