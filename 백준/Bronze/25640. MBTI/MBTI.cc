#include <iostream>
#include <string>
using namespace std;


int main(void)
{
    string word;
    int n;
    
    cin>>word;
    string a;
    cin>>n;
    int count=0;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        if(a==word)
        {
            count++;
        }
    }
    cout<<count;

    return 0;
}