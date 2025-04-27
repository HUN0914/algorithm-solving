#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    string str;
    cin>>str;
    stack<int> s;
    int result=0;

    for (int i=0; i<str.length(); i++) {
        if (str[i]=='('&&str[i+1]==')') {
            result+=s.size();
            i++;
        }
        else if (str[i]=='(') {
            s.push(i);
        }
        else if (str[i]==')'){
            result++;
            s.pop();
        }
    }

    cout<<result;


    return 0;
}