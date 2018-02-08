#include<iostream>
using namespace std;
int main()
{int i,n,a[1000],s=1;
cin>>n;
for(i=1;i<=n;i++)
cin>>a[i];
for(i=2;i<=n-1;i++)
if((a[i]>a[i+1]&&a[i]>a[i-1])||(a[i]<a[i+1]&&a[i]<a[i-1]))s++;
cout<<s;
return 0;   
} 