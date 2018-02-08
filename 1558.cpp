#include<iostream>
using namespace std;
int main()
{int a[101],s,n,k,j,i;
 cin>>n;
 for(i=1;i<=n;i++)
 cin>>a[i];
 cin>>s;
 for(i=1;i<=n-1;i++)
 if(s==a[i])
   {
    for(j=i;j<=n-1;j++)a[j]=a[j+1];
    for(j=1;j<=n-1;j++)cout<<a[j]<<" ";
    return 0;                
   }
 for(i=1;i<=n;i++)
   {
    if(s>a[i]&&(s<a[i+1])){k=i+1;break;}
    if(s<a[1]){k=1;break;}
    if(s>a[n]){k=n+1;break;}
   } 
 for(i=n;i>=k;i--)a[i+1]=a[i];
 a[k]=s;
 for(i=1;i<=n+1;i++)cout<<a[i]<<" ";      
 return 0;   
}