#include<iostream>
using namespace std;
struct edge{int to,next;}a[20005];
int n,s,t,cnt=0,h[105]={0},low[105]={0},dfn[105]={0},sign=0,prt[105]={0},ans=105;
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void init()
{
	cin>>n;int x,y;
	while(1)
	{
		cin>>x>>y;
		if(x==0&&y==0)break;
		add(x,y);
		add(y,x);
	}
	cin>>s>>t;
}
void check(int x)
{
	if(x==s)return;
	if(low[x]>=dfn[prt[x]]&&prt[x]!=s&&prt[x]<ans)ans=prt[x];
	check(prt[x]);
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
int main()
{
 	init();
 	dfs(s);
 	check(t);
 	if(ans==105)cout<<"No solution"<<endl;
 	else cout<<ans;
	return 0;
}
/*
5
2 1
2 5
1 4
5 3
2 3
5 1
0 0
4 2
*/