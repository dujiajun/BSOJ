#include<iostream>
using namespace std;

int main()
{
    int num[50]={1,1,1},n;
    cin>>n;
    if(n<4)cout<<1;
    else 
    {
         for(int i=4;i<=n;i++)
         {
                 num[i-1]=num[i-2]+num[i-4];
         }
         cout<<num[n-1];
    }
    return 0;
    }