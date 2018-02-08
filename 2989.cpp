#include<iostream>
using namespace std;
struct edge{int to,next;}a[10005];
int n,m,cnt,h[205],prt[205],dfn[205],low[205],sign,ma[205][205];
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void dfs(int u)
{
	dfn[u]=low[u]=++sign;
	int v;
	for(int i=h[u];i;i=a[i].next)
	if(a[i].to!=prt[u])
	{
		v=a[i].to;
		if(!dfn[v])
		{
			prt[v]=u;
			dfs(v);
			low[u]=min(low[v],low[u]);
			if(low[v]>dfn[u])ma[u][v]=ma[v][u]=1;
		}
		else low[u]=min(low[u],dfn[v]);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)if(ma[i][j])cout<<i<<" "<<j<<endl;
	return 0;
}
/*
6 6
1 2
2 3
2 4
3 5
4 5
5 6
*/