#include<iostream>

using namespace std;
int main()
{
    int L,R,t=0;
    cin>>L>>R;
    for(int i=L;i<=R;i++)
    {
            int n=i;
            while(n!=0)
            {
                       if(n%10==2)t++;
                       n/=10;
            }
    }
    cout<<t;
    return 0;
    }