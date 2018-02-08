#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    long long a[60]={0,1};
    int n;
    cin>>n;
    for(int i=2;i<60;i++)
    {
            a[i]=a[i-1]+a[i-2];
    }
    cout<<a[n-1];
    return 0;
}