#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{  
   int n;
   cin>>n;
   int a[100],total=0,count=0;
   for(int i=0;i<n;i++){cin>>a[i];total+=a[i];}
   for(int i=0;i<n;i++)a[i]-=total/n;
   for(int i=0;i<n-1;i++)
   	if(a[i]!=0){a[i+1]+=a[i];count++;}	
   cout<<count;
   return 0;
}