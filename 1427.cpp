#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int INF=0x7fffffff/2;
int map[45][45]={0},n,m,kk;
void solve()
{
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(map[i][k]+map[k][j]<map[i][j])
			map[i][j]=map[i][k]+map[k][j];
	int x,y;
	cin>>kk;
	for(int i=1;i<=kk;i++)
	{
		cin>>x>>y;
		for(int j=1;j<=n;j++)
			if(map[x][j]+map[j][y]==map[x][y])cout<<j<<" ";
		cout<<endl;
	}
}
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(i!=j)map[i][j]=map[j][i]=INF;
		else map[i][j]=0;
	int x,y;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		map[x][y]=map[y][x]=1;
	}
}
int main()
{
	init();
	solve();
	return 0;
}