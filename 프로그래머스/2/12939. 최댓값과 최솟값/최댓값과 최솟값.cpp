#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<string>v;
    vector<int> v1;
    string word;
    
    stringstream ss(s);
    
    while(ss>>word){
        v.push_back(word);
    }
    
    for(int i=0; i<v.size(); i++){
        int value=stoi(v[i]);
        v1.push_back(value);
    }
    
    sort(v1.begin(), v1.end());
    string first=to_string(v1[0]);
    string last=to_string(v1[v1.size()-1]);
    answer=first+" "+last;
    
    return answer;
}