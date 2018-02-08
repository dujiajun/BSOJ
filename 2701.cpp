#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
struct edge{int next,to;}a[1000010]={0};
int n,m,fa[500005]={0},q,p[500005][20]={0},vst[500005]={0},d[500005]={0},h[500005]={0},cnt=0;
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void dfs(int x,int dp)
{
	vst[x]=1;d[x]=dp;
	for(int i=h[x];i;i=a[i].next)
		if(vst[a[i].to]==0)dfs(a[i].to,dp+1);
}
void init()
{
	int x,k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(k==0)fa[k]=k;
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&x);
			fa[x]=i;
			add(x,i);
			add(i,x);
		}
	}
	scanf("%d",&m);
}
void st()
{
	int t=log2(n);
	memset(p,-1,sizeof(p));
	for(int i=1;i<=n;i++)p[i][0]=fa[i];
	for(int j=1;j<=t;j++)
	for(int i=1;i<=n;i++)
		if(p[i][j-1]!=-1)p[i][j]=p[p[i][j-1]][j-1];
}
int lca(int a,int b)
{
	if(d[a]<d[b])swap(a,b);
	int k=log2(d[a]);
	for(int i=k;i>=0;i--)
		if(d[a]-(1<<i)>=d[b])a=p[a][i];
	if(a==b)return a;
	for(int i=k;i>=0;i--)
		if(p[a][i]!=-1&&p[a][i]!=p[b][i]){a=p[a][i];b=p[b][i];}
	return p[a][0];
}
int main()
{
	init();
	dfs(1,1);
	st();
	for(int i=1,a,b;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",d[lca(a,b)]);
	}
	return 0;
} 