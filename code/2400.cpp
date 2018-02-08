#include<iostream>
using namespace std;
struct edge{int to,next;}a[2000005];
int m,n,k,l,h[100005],cnt=0,
	low[100005]={0},dfn[100005]={0},
	sign=0,prt[100005]={0},ans=0,
	A[100005]={0},B[100005]={0};
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void init()
{
	cin>>n>>m>>k>>l;
	for(int i=1,y;i<=k;i++){cin>>y;A[y]=1;}
	for(int i=1,y;i<=l;i++){cin>>y;B[y]=1;}
	for(int i=1,x,y;i<=m;i++)
	{
		cin>>x>>y;
		add(x,y);add(y,x);
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
				A[u]+=A[v];
				B[u]+=B[v];
				if(low[v]>dfn[u]&&(A[v]==0||B[v]==0||A[v]==k||B[v]==l))ans++;
			}
			else low[u]=min(low[u],dfn[v]);
		}
	}
}
int main()
{
 	init();
 	dfs(1);
 	cout<<ans<<endl;
	return 0;
}