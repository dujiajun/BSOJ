#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[50001]={0},b[10001]={0},i,j,minn,maxx,t;
int main()
{  
   cin>>n;
   for(i=1;i<n+1;i++)cin>>a[i];
   sort(a+1,a+n+1);
   for(i=1;i<=n;i++) b[i]=a[i];
   for(i=1;i<=n-1;i++)
   { 
      maxx=a[i]*a[i+1]+1;
      j=i+1;
      while(a[j+1]<maxx&&j+1<=n){a[j]=a[j+1];j++;}
      a[j]=maxx;
   }
   for(i=n-1;i>=1;i--)b[i]=b[i+1]*b[i]+1;
   minn=b[1];
   cout<<maxx-minn;
 }