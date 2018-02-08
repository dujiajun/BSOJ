#include<iostream>
using namespace std;
struct edge{int to,next;}a[40005];
int n,m,low[5005]={0},dfn[5005]={0},prt[5005]={0},
	sign=0,con[5005]={0},tot=0,stack[5005]={0},
	be[5005]={0},cnt=0,h[5005]={0},bcc=0,ans=0;
bool vst[5005][5005]={0};
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void dfs(int u)
{
	low[u]=dfn[u]=++sign;
	stack[++tot]=u;
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
	int y;
	if(low[u]==dfn[u])
	{
		bcc++;
		do
		{
			y=stack[tot--];
			be[y]=bcc;
		}while(y!=u);
	}
}
void init()
{
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		cin>>x>>y;
		if(vst[x][y]==0)
		{
			add(x,y);
			add(y,x);
			vst[x][y]=1;
		}
	}
}
void Get()
{
	for(int i=1;i<=n;i++)
	for(int j=h[i];j;j=a[j].next)
	{
		int k=a[j].to;
		if(be[i]!=be[k])con[be[i]]++;	
	}
	for(int i=1;i<=bcc;i++)if(con[i]==1)ans++;
	cout<<(ans+1)/2<<endl;
}
int main()
{
	init();
	dfs(1);
	Get();
	return 0;
}
/*
4 3
1 2
2 3
2 4
*/