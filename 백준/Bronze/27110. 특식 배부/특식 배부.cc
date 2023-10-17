#include <iostream>

using namespace std;

int main(void)
{
    int t;
    int val1,val2,val3;
    
    cin>>t;
    cin>>val1>>val2>>val3;
    
    int sum=0;
    if(val1<=t)
    {
        sum+=val1;
    }
    else
    {
        sum+=t;
    }
    
     if(val2<=t)
    {
        sum+=val2;
    }
    else
    {
        sum+=t;
    }
    
    
    if(val3<=t)
    {
        sum+=val3;
    }
    else
    {
        sum+=t;
    }
    cout<<sum;
    
    return 0;
}