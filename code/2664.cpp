#include<iostream>
#include<cstdio>
using namespace std;
struct edge1{int to,next,v;char c;}a[80005];
struct edge2{int to,next,num;}b[20005];
int n,m,p[40005]={0},k,c1=0,c2=0,h1[40005]={0},h2[40005]={0},ans[10005],fa[40005]={0},vst[40005]={0};
int dp[40005]={0};
void add1(int x,int y,int z)
{a[++c1].to=y;a[c1].next=h1[x];a[c1].v=z;h1[x]=c1;}
void add2(int x,int y,int num)
{b[++c2].to=y;b[c2].next=h2[x];b[c2].num=num;h2[x]=c2;}

void dfs(int x,int fat)
{
	for(int i=h1[x];i;i=a[i].next)
		if(a[i].to!=fat)
		{
			dp[a[i].to]=dp[x]+a[i].v;
			dfs(a[i].to,x);
		}
}
int fet(int x)
{
	if(x==fa[x])return x; 
	fa[x]=fet(fa[x]);
	return fa[x];
}
void init()
{
	char t;
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d%s",&x,&y,&z,&t);
		add1(x,y,z);
		add1(y,x,z);
	}
	scanf("%d",&k);
	for(int i=1,x,y;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		add2(x,y,i);
		add2(y,x,i);
	}
}
void tarjan(int x)
{
	vst[x]=1;fa[x]=x;
	for(int i=h1[x];i;i=a[i].next)
		if(!vst[a[i].to])
		{
			tarjan(a[i].to);
			fa[a[i].to]=x;
		}
	for(int i=h2[x];i;i=b[i].next)
		if(vst[b[i].to])
			ans[b[i].num]=dp[b[i].to]+dp[x]-2*dp[fet(b[i].to)];
}
int main()
{
 	init();
 	dfs(1,0);
 	tarjan(1);
 	for(int i=1;i<=k;i++)printf("%d\n",ans[i]);
	return 0;
}
/*
7 6
1 6 13 E
6 3 9 E
3 5 7 S
4 1 3 N
2 4 20 W
4 7 2 S
3
1 6
1 4
2 6
*/

