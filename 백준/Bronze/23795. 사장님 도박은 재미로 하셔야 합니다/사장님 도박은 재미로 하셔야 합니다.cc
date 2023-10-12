#include <iostream>

using namespace std;

int main(void)
{
    int sum=0;
    int n;
    
    while(1)
    {
        cin>>n;
        if(n==-1)
        {
            break;
        }
        sum+=n;
    }
    cout<<sum;
    return 0;
}