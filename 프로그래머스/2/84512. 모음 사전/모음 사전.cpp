#include <string>
#include <vector>

using namespace std;

char wording[5]={'A','E','I','O','U'};
bool isEnd=false;
int value;
int answer;

void dfs(string word, string createWord){    
    if(createWord==word){
        answer=value;
        return;
    }
    
    if(createWord.size()>=5) return;
    
    for(int i=0; i<5; i++){
        value++;
        dfs(word,createWord+wording[i]);
    }
}

int solution(string word) {
    dfs(word,"");
    return answer;
}