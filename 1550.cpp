#include<iostream>
using namespace std;
int main()
{       int a[21][21],k,i,j,n,min,bj;
        cin>>n;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)cin>>a[i][j];
        for(i=1;i<=n;i++)
        {   bj=0;
            min=a[i][1];k=1;
            for(j=2;j<=n;j++)if(min>a[i][j]){min=a[i][j];k=j;}
            for(j=1;j<=n;j++)if(min<a[j][k]){bj=1;break;}
            if(bj==0)cout<<"("<<i<<","<<k<<")";            
                       
        }
        return 0;    
    
}