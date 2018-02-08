#include<iostream>
using namespace std;
const int INF=0xfffffff;
int n,m,map[105][105]={INF},s,t,g[105][105]={0};
void init()
{
	int x,y,z;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(i==j)map[i][j]=0;else map[i][j]=INF;
	for(int j=1;j<=m;j++)
	{
		cin>>x>>y>>z;
		map[x][y]=min(map[x][y],z);
		g[x][y]=g[y][x]=1;
		map[y][x]=min(map[y][x],z);
	}
	cin>>s>>t;
}
void floyd()
{
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(map[i][j]==map[i][k]+map[k][j])g[i][j]+=g[i][k]*g[k][j];
		if(map[i][j]>map[i][k]+map[k][j])
		{
			map[i][j]=map[i][k]+map[k][j];
			g[i][j]=g[i][k]*g[k][j];
		}
	}
}
int main()
{
	init();
	floyd();
	if(map[s][t]==INF)cout<<"poor ty"<<endl;
	else cout<<g[s][t]<<endl;
	return 0;
}
/*
3 3
1 2 1
2 3 2
1 3 3
1 3
*/