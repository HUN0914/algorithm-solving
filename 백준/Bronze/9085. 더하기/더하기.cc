#include <iostream>

using namespace std;

int main(void)
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;
        int sum=0;
        for(int j=0; j<n; j++)
        {
            int val;
            cin>>val;
            sum+=val;
        }
        cout<<sum<<"\n";
    }
    
return 0;
}