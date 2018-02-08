#include<iostream>
using namespace std;

int main()
{
    int n,sum=1;
    cin>>n;
    int i=1;
    while(i<n)
    {
         sum=(sum+1)*2;
         i++;
    }
    cout<<sum;
    return 0;
}
