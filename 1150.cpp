#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    long n,sum,b=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {   sum=1;
       for(int j=1;j<=i;j++)
         sum*=j;
         b+=sum;
    }
    cout<<b<<endl;
    return 0;
}
