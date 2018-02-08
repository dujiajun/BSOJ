#include<iostream>
using namespace std;
int a[200005]={0},f[200005]={-0xfffffff};
int main()
{
	int n,maxx=-0xfffffff;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	f[1]=a[1];
	for(int i=2;i<=n;i++)f[i]=max(f[i-1],0)+a[i];
	for(int i=2;i<=n;i++)maxx=max(f[i],maxx);
	cout<<maxx;
	return 0;
} 