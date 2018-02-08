#include<iostream>
#include<cstring>
using namespace std;
struct edge{int to,next;}a[100005];
int n,m,h[5005]={0},cnt=0,dfn[5005]={0},tot=0,bel[5005]={0},scc=0,
	low[5005]={0},stack[5005]={0},instack[5005]={0},sign=0,
	size[5005]={0},minn[5005]={0};
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
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
	if(low[u]==dfn[u])
	{
		scc++;int t;minn[scc]=1<<29;
		do
		{
			t=stack[tot--];
			size[scc]++;
			minn[scc]=min(minn[scc],t);
			instack[t]=0;
			bel[t]=scc;	
		}while(t!=u);
	}
}
void init()
{
	cin>>n>>m;
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		if(z==1)add(x,y);
		else {add(x,y);add(y,x);}
	}
}
void solve()
{
	int maxx=0,cd=0,k;
	memset(dfn,0,sizeof(dfn));
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=scc;i++)
	{
		if(size[i]==maxx&&minn[i]<cd){k=i;cd=minn[i];}
		if(size[i]>maxx){k=i;cd=minn[i];maxx=size[i];}
	}
	cout<<maxx<<endl;
	for(int i=1;i<=n;i++)if(bel[i]==k)cout<<i<<" ";
}
int main()
{
	init();
	solve();
	return 0;
}
/*
5 5
1 2 1
1 3 2
2 4 2
5 1 2
3 5 1
*/