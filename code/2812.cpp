#include<iostream>
using namespace std;
int maxx=0,minn,a[10002],b[102],n,m,t;
int main()
{   
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)b[i]=a[i];
	for(int i=m+1;i<=n;i++)
	{
  	    minn=0xfffffff/2;
		for(int j=1;j<=m;j++)if(minn>b[j]){minn=b[j];t=j;}
		b[t]=b[t]+a[i];
	}
	for(int i=1;i<=m;i++)if(maxx<b[i])maxx=b[i];
	cout<<maxx<<endl;
	return 0;
}