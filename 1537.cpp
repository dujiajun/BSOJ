#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
            int t=i,m=0;
            while(t!=0)
            {
                       m+=(t%10)*(t%10)*(t%10);
                       t=t/10;
            }
            if(m==i)cout<<i<<endl;
    }
    
    return 0;
}