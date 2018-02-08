#include <iostream>
using namespace std;
int sum=-0xfffffff,n,f[301][301]={0},a[301][301]={0},t;
int main()
{
   cin>>n;
   for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)cin>>a[i][j];
   for(int i=1;i<=n;i++)f[1][i]=a[1][i];
   for(int i=2;i<=n;i++)
     for(int j=1;j<=n;j++)
        f[i][j]=f[i-1][j]+a[i][j]; 
   for(int i=1;i<=n;i++)  
    {
      for(int j=i;j<=n;j++)  
       {
         t=f[j][1]-f[i-1][1]; 
         for(int k=2;k<=n;k++)  
		  {
            t=max(t,0)+f[j][k]-f[i-1][k];
            if(t>sum)sum=t;
          }
       }
    }
   cout<<sum<<endl;
   return 0;
}
