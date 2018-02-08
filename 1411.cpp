#include<iostream>
#include<algorithm>
using namespace std;
struct edge{int s,t,v;}a[1000005]={0};
int n,fa[1005]={0},cnt=0,ans=0;
bool cmp(edge e1,edge e2){return e1.v<e2.v;}
void add(int x,int y,int v)
{
	a[++cnt].s=x;
	a[cnt].t=y;
	a[cnt].v=v;
}
int getfa(int x)
{
	if(fa[x]==x)return x;
	fa[x]=getfa(fa[x]);
	return fa[x];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1,v;j<=n;j++)
	{
		cin>>v;
		if(j>i)add(i,j,v);
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=cnt;i++)
	{
		int f1=getfa(a[i].s);
		int f2=getfa(a[i].t);
		if(f1!=f2)
		{
			fa[f1]=f2;
			ans+=a[i].v;
		}
	}
	cout<<ans;
	return 0;
}
/*
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
*/