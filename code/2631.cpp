#include<iostream>
#include<iomanip>
using namespace std;
int map[55][55][55],n,m,q;
double ans=1<<29;
int main()
{
	cin>>n>>m;
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)map[k][i][j]=1<<29;
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		map[1][x][y]=z;
	}
	for(int p=2;p<=n;p++)
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	map[p][i][j]=min(map[p][i][j],map[p-1][i][k]+map[1][k][j]);
	cin>>q;
	for(int i=1,x,y;i<=q;i++)
	{
		scanf("%d%d",&x,&y);ans=1<<29;
		for(int j=1;j<=n;j++)
		if(map[j][x][y]!=1<<29)ans=min(ans,double(map[j][x][y])/j);
		if(ans!=1<<29)printf("%.3lf\n",ans);
		else printf("OMG!\n");
	}
	return 0;
}