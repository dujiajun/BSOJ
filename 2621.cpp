#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct edge{int to,next,v;}a[13005];
int n,m,st,ed,cnt=0,h[3000]={0},dis[3000]={0},vst[3000]={0};
void add(int x,int y,int z)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].v=z;
	h[x]=cnt;
}
void dij(int v0)
{
	int minn,k;
	for(int i=1;i<=n;i++)dis[i]=1<<29;
	dis[v0]=0;
	for(int i=1;i<=n;i++)
	{
		minn=1<<29;
		for(int j=1;j<=n;j++)
		    if(minn>dis[j]&&vst[j]==0){minn=dis[j];k=j;}
		vst[k]=1;
		for(int j=h[k];j;j=a[j].next)
			if(vst[a[j].to]==0&&dis[a[j].to]>dis[k]+a[j].v)
				dis[a[j].to]=dis[k]+a[j].v;
	}
}
void init()
{
	cin>>n>>m>>st>>ed;
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
}
int main()
{
	//freopen("heatwv.in","r",stdin);
	//freopen("heatwv.out","w",stdout);
	init();
	dij(st);
	cout<<dis[ed]<<endl;
	return 0;
} 