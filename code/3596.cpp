#include<iostream>
#include<cstring>
using namespace std;
struct edge{int to,next;}a[20005];
int n,cnt,h[105],prt[105],dfn[105],low[105],sign=0,mark[105],son,ans;
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void init()
{
	int x,y;char ch;
	while(1)
	{
		cin>>x;
		if(!x)break;
		while(1)
		{
			scanf("%d%c",&y,&ch);
			add(x,y);add(y,x);
			if(ch=='\n')break;
		}
	}
}
void tarjan(int u)
{
	dfn[u]=low[u]=++sign;int v;
	for(int i=h[u];i;i=a[i].next)
	if(prt[u]!=a[i].to)
	{
		v=a[i].to;
		if(dfn[v]==0)
		{
			prt[v]=u;
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])
			{
				if(!mark[u]){ans++;mark[u]=1;}
				if(dfn[u]==1)son++;
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
}
int main()
{
	while(1)
	{
		memset(prt,0,sizeof(prt));
		memset(h,0,sizeof(h));
		memset(a,0,sizeof(a));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(mark,0,sizeof(mark));
		cnt=0;sign=0;son=0;ans=0;
		cin>>n;
		if(n==0)break;
		init();
		for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
		if(son==1)ans--;
		cout<<ans<<endl;
	}
	return 0;
}