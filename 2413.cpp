#include<iostream>
using namespace std;
struct edge{int to,next;}a[10005];
int n,m,cnt=0,h[1005]={0},out[1005]={0},
	dfn[1005]={0},low[1005]={0},sign=0,bel[1005]={0},rd[1005]={0},tot=0,
	scc=0,size[1005]={0},stack[1005]={0},instack[1005]={0},ans=0,sum=0;
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void init()
{
	cin>>n;
	for(int i=1,x;i<=n;i++)
	{
		while(1)
		{
			cin>>x;
			if(x==0)break;
			add(i,x);
		}
	}
} 
void tarjan(int u)
{
	low[u]=dfn[u]=++sign;
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
		int t;
		scc++;
		do
		{
			t=stack[tot--];
			bel[t]=scc;
			instack[t]=0;
			size[scc]++;
		}while(u!=t);
	}
}
void solve()
{
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++)
	for(int j=h[i];j;j=a[j].next)
	{
		int to=a[j].to;
		if(bel[i]!=bel[to])
		{
			rd[bel[to]]++;out[bel[i]]++;
		}
	}
	for(int i=1;i<=scc;i++)
	{
		if(rd[i]==0)ans++;
		if(out[i]==0)sum++;
	}
	cout<<ans<<endl;
	if(scc==1)cout<<0<<endl;
	else cout<<max(ans,sum)<<endl;
}
int main()
{
	init();
	solve();
	return 0;
}
/*
5
2 4 3 0
4 5 0
0
0
1 0
*/