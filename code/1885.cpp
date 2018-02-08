#include<iostream>
using namespace std;
int n,m,a[1001]={0},f[1001][1001]={0},ans=-1<<29;
int main()
{
 	cin>>n>>m;
 	for(int i=1;i<=n;i++)cin>>a[i];
 	for(int i=1;i<=n;i++)f[1][i]=max(f[1][i-1],0)+a[i];
	for(int i=2;i<=m;i++)
	for(int j=i;j<=n;j++)
	{
		f[i][j]=f[i][j-1]+a[j];
		for(int k=i-1;k<=j-1;k++)f[i][j]=max(f[i][j],f[i-1][k]+a[j]);
	}
	for(int i=1;i<=n;i++)ans=max(ans,f[m][i]);
	cout<<ans;
	return 0;
}
/*
5 2
3 -2 1 2 3
*/