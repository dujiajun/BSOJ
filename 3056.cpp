#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
struct edgepre{int a,b,v;}b[100005];
int n,m,fa[10005],prt[10005],d[10005],e[10005],q,ans=0;
inline bool cmp(edgepre e1,edgepre e2){return e1.v<e2.v;}
int getfa(int x)
{
	if(x==fa[x])return x;
	return fa[x]=getfa(fa[x]);
}
void kruskal()
{
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	int f1,f2;
	for(int i=1;i<=m;i++)
	{
		f1=getfa(b[i].a),f2=getfa(b[i].b);
		if(f1!=f2)
		{
			fa[f1]=f2;
			prt[f1]=f2;
			e[f1]=b[i].v;
		}
	}
}
int LCA(int x,int y)
{
	int a1=0,a2=0,d1=0;
	if(d[y]<d[x])swap(x,y);
	d1=d[y]-d[x];
	for(int i=1;i<=d1;i++)
	{
		a2=max(a2,e[y]);
		y=prt[y];
	}
	while(1)
	{
		if(x==y)return max(a1,a2);
		a1=max(a1,e[x]);
		a2=max(a2,e[y]);
		x=prt[x];
		y=prt[y];
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&b[i].a,&b[i].b,&b[i].v);
	kruskal();
	for(int i=1;i<=n;i++)
	for(int j=prt[i];j;j=prt[j])d[i]++;
	cin>>q;
	for(int i=1,st,ed;i<=q;i++)
	{
		scanf("%d%d",&st,&ed);
		printf("%d\n",LCA(st,ed));
	}
	return 0;
} 
/*
4 5
1 2 10
1 3 20
1 4 100
2 4 30
3 4 10
2
1 4
4 1
*/