#include<iostream>
using namespace std;

int main()
{
    int n,a[40]={1,2};
    cin>>n;
    
    for(int i=2;i<n;i++)
    {
            a[i]=a[i-1]+a[i-2];
    }
    
    cout<<a[n-1];
    return 0;
    }