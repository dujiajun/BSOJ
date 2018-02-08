#include<iostream>
using namespace std;
const int MAXN=200005;
struct edge{int to,next,v;}a[MAXN*5],b[MAXN*5];
struct edget{int a,b,v;}c[MAXN*5];
int n,m,cnt,cnt2,h[MAXN],h2[MAXN];
int sign,dfn[MAXN],low[MAXN],tot,scc,stk[MAXN],bl[MAXN];
int q[MAXN],dis[MAXN];
bool vst[MAXN],instk[MAXN];
void add(int x,int y,int z)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].v=z;
	h[x]=cnt;
}
void addb(int x,int y,int z)
{
	b[++cnt2].to=y;
	b[cnt2].next=h2[x];
	b[cnt2].v=z;
	h2[x]=cnt2;
}
void Tarjan(int u)
{
	dfn[u]=low[u]=++sign;
	instk[u]=1;
	stk[++tot]=u;int v;
	for(int i=h[u];i;i=a[i].next)
	{
		v=a[i].to;
		if(!dfn[v])
		{
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(instk[v])low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		scc++;int tp;
		do
		{
			tp=stk[tot--];
			bl[tp]=scc;
			instk[tp]=0;
		}while(tp!=u);
	}
}
void SPFA(int st)
{
	for(int i=1;i<=scc;i++)dis[i]=1<<29;
	dis[st]=0;vst[st]=1;q[1]=st;
	int l=0,r=1,x,to;
	while(l<r)
	{
		x=q[(++l)%MAXN];vst[x]=0;
		for(int i=h2[x];i;i=b[i].next)
		{
			to=b[i].to;
			if(dis[to]>dis[x]+b[i].v)
			{
				dis[to]=dis[x]+b[i].v;
				if(!vst[to])
				{
					r++;
					q[r%MAXN]=to;
					vst[to]=1;
				}
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&c[i].a,&c[i].b,&c[i].v);
		add(c[i].a,c[i].b,c[i].v);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])Tarjan(i);
	for(int i=1;i<=m;i++)if(bl[c[i].a]!=bl[c[i].b])addb(bl[c[i].a],bl[c[i].b],c[i].v);
	SPFA(bl[1]);
	cout<<dis[bl[n]]<<endl;
	return 0;
}