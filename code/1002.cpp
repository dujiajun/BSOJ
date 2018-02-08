#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{  
   int n,r,ti=0,i=0;
   cin>>n>>r;
   int t[75]={0};
   int a[500];
   for(int i=0;i<n;i++)cin>>a[i];
   sort(a,a+n);

   for(i=0;i<n;i++)
   {
   	t[i%r]=t[i%r]+a[i];
   	ti+=t[i%r];
   }
   cout<<ti;
   return 0;
}