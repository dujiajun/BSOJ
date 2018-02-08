#include<iostream>
using namespace std;
const int MAXN=100005;
struct edge{int to,next,v;}a[MAXN*8];
struct edge2{int a,b,v;}b[MAXN*8],c[MAXN*2];
int n,m,k,cnt,h[MAXN],q[MAXN],dis[MAXN],vst[MAXN],rd[MAXN],ans=0;
inline void add(int x,int y,int z)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].v=z;
	h[x]=cnt;
}
void SPFA(int st)
{
	int l=0,r=1,x,i,to;
	for(int i=1;i<=n;i++)dis[i]=1<<30;
	dis[st]=0;vst[st]=1;q[1]=st;
	while(l<r)
	{
		x=q[(++l)%MAXN];vst[x]=0;
		for(i=h[x];i;i=a[i].next)
		{
			to=a[i].to;
			if(dis[to]>dis[x]+a[i].v)
			{
				dis[to]=dis[x]+a[i].v;
				if(!vst[to])
				{
					q[(++r)%MAXN]=to;
					vst[to]=1;
				}
			}
		}
	}
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&b[i].a,&b[i].b,&b[i].v);
		add(b[i].a,b[i].b,b[i].v);add(b[i].b,b[i].a,b[i].v);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&c[i].b,&c[i].v);
		add(1,c[i].b,c[i].v);
	}
	SPFA(1);
	for(int i=1;i<=m;i++)
	{
		if(dis[b[i].a]+b[i].v==dis[b[i].b])rd[b[i].b]++;
		if(dis[b[i].b]+b[i].v==dis[b[i].a])rd[b[i].a]++;
	}
	for(int i=1;i<=k;i++)
	if(dis[c[i].b]==c[i].v)rd[c[i].b]++;
	else ans++;
	for(int i=1;i<=k;i++)
	if(dis[c[i].b]==c[i].v&&rd[c[i].b]>1){rd[c[i].b]--;ans++;}
	cout<<ans<<endl;
	return 0;
} 