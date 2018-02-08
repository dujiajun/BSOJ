#include<iostream>
#include<cstring>
using namespace std;
int k,c,m,map[500][500]={0},my[500]={0},p[500][500]={0},vst[500]={0};
void build(int x)
{
	memset(p,0,sizeof(p));
	for(int i=1;i<=c;i++)
	for(int j=1;j<=k;j++)
		if(map[k+i][j]<=x)
			for(int t=1;t<=m;t++)
				p[i][(j-1)*m+t]=1;
}
int dfs(int x)
{
	for(int i=1;i<=k*m;i++)
	if(p[x][i]&&!vst[i])
	{
		vst[i]=1;
		if(my[i]==-1||dfs(my[i]))
		{
			my[i]=x;
			return 1;
		}
	}
	return 0;
}
int match()
{
	memset(my,-1,sizeof(my));
	for(int i=1;i<=c;i++)
	{
		memset(vst,0,sizeof(vst));
		if(!dfs(i))return 0;
	}
	return 1;
}
void solve()
{
	int l=1,r=(k+c)*200,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		build(mid);
		if(match())r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
}
void floyd()
{
	int t=k+c;
	for(int h=1;h<=t;h++)
	for(int i=1;i<=t;i++)
	for(int j=1;j<=t;j++)
	if(map[i][j]>map[i][h]+map[h][j])map[i][j]=map[i][h]+map[h][j];
}
int main()
{
	cin>>k>>c>>m;
	for(int i=1;i<=k+c;i++)
	for(int j=1;j<=k+c;j++)
	{
		cin>>map[i][j];
		if(!map[i][j])map[i][j]=1<<29;
	}
	floyd();
	solve();
	return 0;
}
/*
2 3 2
0 3 2 1 1
3 0 3 2 0
2 3 0 1 0
1 2 1 0 2
1 0 0 2 0
*/