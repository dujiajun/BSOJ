#include<iostream>
#include<cstring>
using namespace std;
int n,m,t,f[50][50][50]={0},a[50]={0};
void solve()
{
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	for(int k=0;k<=t;k++)
	{
		if(k>=a[i])f[i][j][k]=max(f[i-1][j][k-a[i]]+1,f[i-1][j-1][t]);
		else f[i][j][k]=max(f[i-1][j][k],f[i][j-1][t]);
	}
	cout<<f[n][m][t]<<endl;
}
int main()
{
	while(cin>>n>>t>>m)
	{
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		solve();
	}
	return 0;
}
/*
4 5 2
4 3 4 2
*/