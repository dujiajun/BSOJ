#include<iostream>
#include<cstdio>
using namespace std;
const int INF=1<<30,MAXN=100005;
struct edge{int to,next;}a[MAXN*4];
int n,m,cnt,h[MAXN],vst[MAXN],dis[MAXN],q[MAXN],usd[MAXN],f[MAXN];
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
int SPFA(int st)
{
	int l=0,r=1,x,to;
	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[st]=0;vst[st]=1;q[r]=st;
	while(l<r)
	{
		x=q[(++l)%MAXN];
		for(int i=h[x];i;i=a[i].next)
		{
			to=a[i].to;
			if(dis[to]>dis[x]+1)
			{
				dis[to]=dis[x]+1;
				usd[to]++;
				if(usd[to]>=n)return 0;
				if(!vst[to])
				{
					r++;
					vst[to]=1;
					q[r%MAXN]=to;
				}
			}
			if(dis[to]==dis[x]+1)f[to]=(f[x]+f[to])%100003;
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	f[1]=1;
	SPFA(1);
	for(int i=1;i<=n;i++)printf("%d\n",f[i]);
	return 0;
} 