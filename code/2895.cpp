#include<iostream>
#include<cstring>
using namespace std;
int n,m,map[105][105]={0},INF=1<<29;
void floyd()
{
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
}
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(i!=j)map[i][j]=INF;
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		map[x][y]=map[y][x]=z;
	}
}
int main()
{
	int k,maxx=-INF;
	init();
	floyd();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)maxx=max(maxx,map[i][j]);
	cout<<maxx;
	return 0;
}
/*
3 3
1 2 1
2 3 2
1 3 2
*/