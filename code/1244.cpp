#include<iostream>
using namespace std;

int main()
{
    int m,n,i=0,a[30]={0};
    char b[30];
    cin>>m>>n;;
    int s=m;
    
     while(m>0)
               {
               i++;
              a[i]=m%n;
              m=m/n;
              }
    cout<<"("<<s<<")10=(";
    for(int j=i;j>0;j--)
    {
            if(a[j]>=10)
            b[j]=char(a[j]-10+'A'); 
            if(a[j]<10)
            b[j]=char(a[j]+'0');
    }
    for(int j=i;j>0;j--)
    {
            cout<<b[j];
    }
    cout<<")"<<n;
    return 0;
}