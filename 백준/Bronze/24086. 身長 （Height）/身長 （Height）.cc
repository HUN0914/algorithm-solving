#include <iostream>

using namespace std;

int main(void)
{
    int n,m;
    
    cin>>n>>m;
    
    int result=n-m;
    
    if(result<0)
    {
        cout<<-result;
    }
    else
    {
        cout<<result;
    }
    
    
    return 0;
}