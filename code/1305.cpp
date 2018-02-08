#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100001,INF=1<<29;
int h[maxn],cnt=0,vst[maxn]={0},dis[maxn]={0},n,m,fa[maxn]={0},ans=0;
struct edge{int a,b,v;}a[maxn];
bool cmp(edge e1,edge e2){return e1.v<e2.v;}
int getfa(int x)
{
	if(fa[x]==x)return x;
	fa[x]=getfa(fa[x]);
	return fa[x];
}
void add(int x,int y,int v)
{
	a[++cnt].a=x;
	a[cnt].b=y;	
	a[cnt].v=v;
}
void kruskal()
{
	int f1,f2;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		f1=getfa(a[i].a);
		f2=getfa(a[i].b);
		if(f1!=f2)
		{
			ans+=a[i].v;
			fa[f1]=f2;
		}
	}
}
void init()
{
	cin>>n>>m;
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		add(x,y,z);
		//add(y,x,z);
	}
}
int main()
{
 	init();
 	sort(a+1,a+m+1,cmp);
 	kruskal();
 	cout<<ans;
	return 0;
}
