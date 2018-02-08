#include<iostream>
#include<ctime>
#include<cstring>
using namespace std;
const int INF=1<<29,MAXN=10005;
struct edge{int to,next,v;}a[200005];
int m,n,p,k,cnt,h[MAXN],ans,vst[MAXN],dis[MAXN],q[MAXN],v[MAXN];
inline void add(int x,int y,int z)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].v=z;
	h[x]=cnt;
}
void spfa(int st)
{
	memset(vst,0,sizeof(vst));
	int l=1,r=1,x,to;
	dis[st]=0;q[1]=st;
	while(l<=r)
	{
		x=q[l%MAXN];vst[x]=0;
		if(dis[x]>=k){l++;continue;}
		if(!v[x]){v[x]=1;ans++;}
		for(int i=h[x];i;i=a[i].next)
		{
			to=a[i].to;
			if(dis[to]>dis[x]+a[i].v)
			{
				dis[to]=dis[x]+a[i].v;
				if(!vst[to])
				{
					r++;
					q[r%MAXN]=to;
					vst[to]=1;
				}
			}
		}
		l++;
	}
}
int main()
{
	cin>>n>>m>>p>>k;
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	for(int i=1;i<=n;i++)dis[i]=INF;
	int ft,t=0;
	//cin>>ft;
	//spfa(ft);
	for(int i=1,x;i<=p;i++)
	{
		scanf("%d",&x);
		spfa(x);
		printf("%d\n",n-ans);
	}
	return 0;
}
/*
7 6 3 3
1 2 1
1 3 1
2 5 1
3 6 1
1 4 1
4 7 2
2
1
4
*/