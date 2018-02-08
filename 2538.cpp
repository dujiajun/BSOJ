#include<iostream>
#include<cstring>
using namespace std;
const int INF=1<<29;
struct edget{int a,b,v;}b[50005];
struct edge{int to,next,f,op;}a[100005];
int cnt,h[305],n,m,t,maxx,ans,gap[305],dis[305];
void addedge(int x,int y,int z)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].f=z;
	a[cnt].op=cnt&1?cnt+1:cnt-1;
	h[x]=cnt;
}
int sap(int x,int fl)
{
	if(x==n)return fl;
	int tmp=fl,dt,minn=n;
	for(int i=h[x];i;i=a[i].next)
	if(a[i].f&&dis[x]==dis[a[i].to]+1)
	{
		dt=sap(a[i].to,min(tmp,a[i].f));
		tmp-=dt;
		a[i].f-=dt;
		a[a[i].op].f+=dt;
		if(dis[1]==n||tmp==0)return fl-tmp;
	}
	for(int i=h[x];i;i=a[i].next)
	if(a[i].f)minn=min(minn,dis[a[i].to]+1);
	if(--gap[dis[x]]==0)dis[1]=n;
	else ++gap[dis[x]=minn];
	return fl-tmp;
}
bool Construct(int x)
{
	memset(h,0,sizeof(h));
	cnt=0;ans=0;
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	for(int i=1;i<=m;i++)
	if(b[i].v<=x)
	{
		addedge(b[i].a,b[i].b,1);
		addedge(b[i].b,b[i].a,1);
	}
	while(dis[1]<n&&ans<t)ans+=sap(1,INF);
	return ans>=t;
}
int main()
{
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].a>>b[i].b>>b[i].v;
		maxx=max(maxx,b[i].v);
	}
	int l=1,r=maxx,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(Construct(mid))r=mid;
		else l=mid+1;
	}
	cout<<r<<endl;
	return 0;
}
/*
7 9 2
1 2 2
2 3 5
3 7 5
1 4 1
4 3 1
4 5 7
5 7 1
1 6 3
6 7 3
*/