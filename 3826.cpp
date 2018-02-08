#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
struct edget{int a,b,v;}b[50005];
int n,m,cnt,h[10005],prt[10005],q,st[30005],ed[30005],fat[10005],d[10005],e[10005];
inline bool cmp(edget e1,edget e2){return e1.v>e2.v;}
void init()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&b[i].a,&b[i].b,&b[i].v);
	cin>>q;
	for(int i=1;i<=q;i++)scanf("%d%d",&st[i],&ed[i]);
}
int getfa(int x)
{
	if(fat[x]==x)return x;
	return fat[x]=getfa(fat[x]);
}
int LCA(int x,int y)
{
	if(d[x]<d[y])swap(x,y);
	int a1=1<<29,a2=1<<29,dt=d[x]-d[y];
	for(int i=1;i<=dt;i++)
	{
		a1=min(a1,e[x]);
		x=prt[x];
	}
	while(1)
	{
		if(x==y)return min(a1,a2);
		a1=min(a1,e[x]);x=prt[x];
		a2=min(a2,e[y]);y=prt[y];
	}
}
void kruskal()
{
	for(int i=1;i<=n;i++)fat[i]=i;
	sort(b+1,b+m+1,cmp);
	int f1,f2;
	for(int i=1;i<=m;i++)
	{
		f1=getfa(b[i].a);f2=getfa(b[i].b);
		if(f1!=f2)
		{
			fat[f1]=f2;
			prt[f1]=f2;e[f1]=b[i].v;
		}
	}
}
void solve()
{
	int f1,f2;
	for(int i=1;i<=q;i++)
	{
		f1=getfa(st[i]);f2=getfa(ed[i]);
		if(f1!=f2)
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",LCA(st[i],ed[i]));
	}
}
int main()
{
	init();
	kruskal();
	for(int i=1;i<=n;i++)
	for(int j=prt[i];j;j=prt[j])d[i]++;
	solve();
	return 0;
}