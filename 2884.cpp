#include<iostream>
using namespace std;
const int INF=1<<29;
int n,m,map[505][505],dis[505][505],ans=INF,x1,x2;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)if(i!=j)map[i][j]=INF;
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		map[x][y]=map[y][x]=dis[x][y]=dis[y][x]=z;
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(map[i][k]!=INF&&map[k][j]!=INF&&map[i][j]>map[i][k]+map[k][j])map[i][j]=map[i][k]+map[k][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(dis[i][j])
	{
		int minn=map[1][i]+dis[i][j]/2+map[j][n];
		if(ans>minn){ans=minn;x1=min(i,j);x2=max(i,j);}
	}
	cout<<x1<<" "<<x2<<endl<<ans;
	return 0;
}