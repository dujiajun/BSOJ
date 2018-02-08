#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[1005][2005],f[2005][1005]={0},ans=1<<29;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(j==1)f[i][j]=min(f[i-1][1],f[i-1][m])+a[j][i];
		else f[i][j]=min(f[i-1][j],f[i-1][j-1])+a[j][i];
	}
	for(int i=1;i<=m;i++)ans=min(ans,f[n][i]);
	cout<<ans;
	return 0;
}
/*
4 3 
2 6 1 8
3 6 2 6
4 2 3 6
*/