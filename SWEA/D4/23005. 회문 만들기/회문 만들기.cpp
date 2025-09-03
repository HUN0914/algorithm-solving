#include <iostream>

using namespace std;

int main() {

    int t;
    cin>>t;

    while (t--) {
        string content;
        bool isTrue=true;
        int counting=0;
        cin>>content;

        int start=0;
        int end=content.size()-1;
        while (true) {
            if (start>=end) break;

            if (content[start]!=content[end]) {
                if (content[start]=='x') {
                    start++;
                    counting++;
                    continue;
                }
                if (content[end]=='x') {
                    end--;
                    counting++;
                    continue;
                }
                isTrue=false;
                break;
            }
            start++;
            end--;
        }
        if (isTrue) cout<<counting<<"\n";
        else cout<<"-1"<<"\n";
    }

    return 0;
}