#include<iostream>
using namespace std;
int dis[105][105],g[105][105],n,m,ans=1<<29;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		g[i][j]=g[j][i]=1<<29;
		dis[i][j]=dis[j][i]=1<<29;
	}
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		g[x][y]=g[y][x]=z;
		dis[x][y]=dis[y][x]=z;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=k-1;i++)
		for(int j=i+1;j<=k-1;j++)ans=min(ans,g[i][k]+g[k][j]+dis[i][j]);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(dis[i][k]!=1<<29&&dis[k][j]!=1<<29&&dis[i][j]>dis[i][k]+dis[k][j])dis[i][j]=dis[i][k]+dis[k][j];
	}
	if(ans!=1<<29)cout<<ans<<endl;
	else cout<<"No solution.";
	return 0;
} 
/*
5 6
1 4 1
3 1 10
1 2 16
2 3 100
2 5 15
5 3 20
*/