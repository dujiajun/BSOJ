#include<iostream>
using namespace std;
struct edge{int to,next;}a[2500005];
const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int n,l,w,cnt=0,h[250005],map[505][505]={0},dfn[250005]={0},low[250005]={0},sign=0,
	scc=0,stack[250005]={0},instack[250005]={0},tot=0,
	bel[250005]={0},in[250005]={0},out[250005]={0};
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void init()
{
	cin>>w>>l;
	for(int i=1;i<=l;i++)
	for(int j=1;j<=w;j++)cin>>map[i][j];
	for(int i=1;i<=l;i++)
		for(int j=1;j<=w;j++)
		{
			int u=(i-1)*w+j;
			for(int k=0;k<4;k++)
			{
				int nx=i+dx[k],ny=j+dy[k];
				int v=(nx-1)*w+ny;
				if(nx<1||nx>l||ny<1||ny>w)continue;
				if(map[i][j]>=map[nx][ny])add(u,v);
			} 
		}
	n=l*w;
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
		}while(t!=u);
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
			in[bel[to]]++;
			out[bel[i]]++;
		}
	}
	int as1=0,as2=0;
	for(int i=1;i<=scc;i++)
	{
		if(!in[i])as1++;
		if(!out[i])as2++;
	}
	if(scc==1)cout<<0<<endl;
	else cout<<max(as1,as2)<<endl;
}
int main()
{
	init();
	solve();
	return 0;
}
/*
9 3
1 1 1 2 2 2 1 1 1
1 2 1 2 3 2 1 2 1
1 1 1 2 2 2 1 1 1
*/