#include<iostream>
using namespace std;
int ans=0,n,a[2223],f[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{  
	cin>>n;
   	n=n-4;
   	for(int i=0;i<10;i++)a[i]=f[i];
   	for(int i=10;i<=2222;i++)a[i]=a[i/10]+f[i%10];
   	for(int i=0;i<=1111;i++)
    for(int j=i;j<=1111;j++)
    if(a[i]+a[j]+a[i+j]==n)if(i==j)ans=ans+1;else ans=ans+2;
   	cout<<ans<<endl;
   	return 0;
}