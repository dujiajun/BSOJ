#include<iostream>
using namespace std;
int main()
{
    long long n,i,f[21];
    cin>>n;
    f[1]=0;f[2]=1;f[3]=2;
    for(i=4;i<=n;i++)
    f[i]=(f[i-1]+f[i-2])*(i-1);
    cout<<f[n]<<endl; 
    return 0;
}