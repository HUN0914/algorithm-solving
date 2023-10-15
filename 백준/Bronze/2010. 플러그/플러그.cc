#include <iostream>

using namespace std;

int main(void)
{
    int t;
    
    int val;
    int sum=0;
    
    cin>>t;
    
    for(int i=0; i<t; i++)
    {
        cin>>val;
        sum+=val;
    }
    
    cout<<sum-(t-1);
    
    
    return 0;
}