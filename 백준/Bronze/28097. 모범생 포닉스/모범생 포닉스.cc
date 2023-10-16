#include <iostream>

using namespace std;

int main(void)
{
    int t;
    cin>>t;
    
    int val=0;
    int sum=0;
    for(int i=0; i<t; i++)
    {
        cin>>val;
        sum+=val;
    }
    
    cout<<(sum+(8*(t-1)))/24<<" "<<(sum+(8*(t-1)))%24;
        
    
    return 0;
}