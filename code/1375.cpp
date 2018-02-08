#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
struct edge{int to,next;}a[400005];
int n,m,cnt,h[200005],p[200005][20],prt[200005],vst[200005],d[200005];
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
	if(!vst[a[i].to])dfs(a[i].to,dp+1);
}
void ST()
{
	memset(p,-1,sizeof(p));
	int t=log2(n);
	for(int i=1;i<=n;i++)p[i][0]=prt[i];
	for(int j=1;j<=t;j++)
	for(int i=1;i<=n;i++)if(p[i][j-1]!=-1)p[i][j]=p[p[i][j-1]][j-1];
}
int LCA(int a,int b)
{
	if(d[a]<d[b])swap(a,b);
	int t=log2(d[a]);
	for(int i=t;i>=0;i--)if(d[a]-(1<<i)>=d[b])a=p[a][i];
	if(a==b)return a;
	for(int i=t;i>=0;i--)
	if(p[a][i]!=-1&&p[a][i]!=p[b][i]){a=p[a][i];b=p[b][i];}
	return p[a][0];
}
int main()
{
	cin>>n>>m;
	for(int i=1,x,y;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);prt[y]=x;
	}
	for(int i=1;i<=n;i++)if(prt[i]==0){dfs(i,1);break;}
	ST();
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",LCA(x,y));
	}
	return 0;
}