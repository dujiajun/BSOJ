#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n,s=0,t=0,max=0,b;
    char a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
            cin>>a;
            s=0;
            t=0;
            while(a!='E')
            {
                 if(a=='Y'){s++;t++;}
                 if(t==3){s++;t=0;}
                 if(a=='N')t=0;        
                 cin>>a;
            }
            if(max<=s)
            {
                      max=s;
                      b=i;
            }
    }
    cout<<b<<endl<<max;
    return 0;
    }
