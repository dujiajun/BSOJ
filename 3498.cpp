#include<iostream>
#include<algorithm>
using namespace std;
int n,m,c[100005]={0},x[5005]={0},f[5005]={0};
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=m;i++)cin>>c[i];
	for(int i=m-1;i>=1;i--)c[i]=min(c[i],c[i+1]);
	sort(x+1,x+n+1);
	for(int i=1;i<=n+1;i++)f[i]=0x7fffffff;
	f[1]=0;
	for(int i=2;i<=n+1;i++)
	for(int j=1;j<i;j++)f[i]=min(f[i],f[j]+c[x[i-1]-x[j]+1]);
	cout<<f[n+1];
	return 0;
}