#include <iostream>

using namespace std;

int main(void)
{
    int result=0;
    int t;
    int val;
    
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>val;
        result+=val;
    }
    cout<<result;
    
    return 0;
}