#include<iostream>
using namespace std;
int v[205]={0},w[205]={0},f[205]={0};
int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n;i++)cin>>w[i]>>v[i];
	for(int i=1;i<=n;i++)
		for(int j=w[i];j<=m;j++)
			f[j]=max(f[j],f[j-w[i]]+v[i]);
	int maxx=f[0];
	for(int i=1;i<=m;i++)maxx=max(maxx,f[i]);
	cout<<maxx;
	return 0;
} 