#include<iostream>
#include<cstring>
using namespace std;
struct edge{int to,next;}a[100005];
int n,m,h[10086]={0},cnt=0,dfn[10086]={0},tot=0,bel[10086]={0},scc=0,
	low[10086]={0},stack[10086]={0},instack[10086]={0},sign=0,rd[10086]={0},
	size[10086]={0},ans=0;
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void init()
{
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		cin>>x>>y;
		add(x,y);
	}
}
void tarjan(int u)
{
	dfn[u]=low[u]=++sign;
	stack[++tot]=u;instack[u]=1;
	for(int i=h[u];i;i=a[i].next)
	{
		int to=a[i].to;
		if(!dfn[to])
		{
			tarjan(to);
			low[u]=min(low[u],low[to]);
		}
		else if(instack[to])low[u]=min(low[u],dfn[to]);
	}
	int t;
	if(low[u]==dfn[u])
	{
		scc++;
		do
		{
			t=stack[tot--];
			instack[t]=0;
			bel[t]=scc;
			size[scc]++;
		}while(t!=u);
	}
}
void solve()
{
	int t=0;
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++)
	for(int j=h[i];j;j=a[j].next)
		if(bel[i]!=bel[a[j].to])rd[bel[i]]++;
	for(int i=1;i<=scc;i++)
		if(rd[i]==0){t++;ans=size[i];}
	if(t==1)cout<<ans<<endl;
	else cout<<0<<endl;
}
int main()
{
	init();
	solve();
	return 0;
}