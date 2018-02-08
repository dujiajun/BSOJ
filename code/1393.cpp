#include<iostream>
#include<cstring>
using namespace std;
struct edge{int to,next;}a[80005];
int m,n,h[15005],cnt=0,low[15005]={0},dfn[15005]={0},sign=0,prt[15005]={0},ans=0;
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void init()
{
	for(int i=1,x,y;i<=n;i++)
	{
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
}
void dfs(int u)
{
	low[u]=dfn[u]=++sign;
	for(int i=h[u];i;i=a[i].next)
	{
		int v=a[i].to;
		if(prt[u]!=v)
		{
			if(dfn[v]==0)
			{
				prt[v]=u;
				dfs(v);
				low[u]=min(low[u],low[v]);
				if(low[v]>dfn[u])ans++;
			}
			else low[u]=min(low[u],dfn[v]);
		}
	}
}
void solve()
{
	while(1)
	{
		memset(prt,0,sizeof(prt));
		memset(a,0,sizeof(a));
		memset(low,0,sizeof(low));
		memset(dfn,0,sizeof(dfn));
		memset(h,0,sizeof(h));
		cnt=0;sign=0;ans=0;
		cin>>m>>n;
		if(m==0&&n==0)break;
		init();
		dfs(1);
		cout<<ans<<endl;
	}
}
int main()
{
 	solve();
	return 0;
}
