#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAXN=10005,MAXM=200005,INF=1<<29;
struct edge{int to,next;}a[MAXM];
int n,m,cnt,h[MAXN],vst[MAXN],st,ed,rd[MAXN],cd[MAXN],q[MAXM],dis[MAXN];
bool w[MAXN];
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void dfs(int x,int frm)
{
	vst[x]=1;
	for(int i=h[x];i;i=a[i].next)
	{
		if(cd[a[i].to]==0&&a[i].to!=ed)w[x]=0;
		if(!vst[a[i].to])dfs(a[i].to,x);
		if(a[i].to!=frm)w[x]=w[x]&&w[a[i].to];
	}
}
void SPFA()
{
	int l=0,r=1,x,to;
	for(int i=1;i<=n;i++)dis[i]=INF;
	q[1]=st;vst[st]=1;dis[st]=0;
	while(l<r)
	{
		x=q[(++l)%MAXM];vst[x]=0;
		for(int i=h[x];i;i=a[i].next)
		{
			to=a[i].to;
			if(dis[to]>dis[x]+1&&w[to]==1)
			{
				dis[to]=dis[x]+1;
				if(!vst[to])
				{
					r++;
					q[r%MAXM]=to;
					vst[to]=1;
				}
			}
		}
	}
	if(dis[ed]!=INF)cout<<dis[ed]<<endl;
	else cout<<-1<<endl;
}
int main()
{
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		rd[y]++;cd[x]++;
		add(x,y);
	}
	for(int i=1;i<=n;i++)w[i]=1;
	cin>>st>>ed;
	dfs(st,0);
	if(!vst[ed])
	{
		cout<<-1<<endl;
		return 0;
	}
	w[st]=1;
	memset(vst,0,sizeof(vst));
	SPFA();
	return 0;
}
