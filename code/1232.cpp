#include<iostream>
using namespace std;
struct edge{int to,next;}a[40000];
int n,m,s,t,cnt=0,h[1005]={0},low[1005]={0},dfn[1005]={0},sign=0,prt[1005]={0},ans1=0,ans2=0,mark[1005]={0},son=0;
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
		add(y,x);
	}
	cin>>s>>t;
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
			}
			else low[u]=min(low[u],dfn[v]);
		}
	}
}
void check(int x)
{  
	if(x==s)return;
   	if(low[x]>=dfn[prt[x]]&&prt[x]!=s)ans1++;
   	if(low[x]>dfn[prt[x]]&&x!=s)ans2++;
   	check(prt[x]);
}
int main()
{
 	init();
 	dfs(s);
 	check(t);
 	cout<<ans1<<endl<<ans2;
	return 0;
}