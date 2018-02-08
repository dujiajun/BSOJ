#include<iostream>
using namespace std;
const int MAXN=20005;
struct edge{int to,next,v;}a[MAXN];
int n,cnt,h[MAXN],minn=1<<29,maxx,dis[MAXN],vst[MAXN],q[MAXN*20],usd[MAXN];
inline void add(int x,int y,int z)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].v=z;
	h[x]=cnt;
}
int SPFA(int st)
{
	for(int i=1;i<=maxx;i++)dis[i]=(1<<29);
	int l=0,r=1,x,to;
	dis[st]=0;vst[st]=1;q[1]=st;
	while(l!=r)
	{
		l=(l+1)%MAXN;
		x=q[l];vst[x]=0;
		for(int i=h[x];i;i=a[i].next)
		{
			to=a[i].to;
			if(dis[to]>dis[x]+a[i].v)
			{
				dis[to]=dis[x]+a[i].v;
				usd[to]++;
				if(usd[to]==maxx)return 0;
				if(!vst[to])
				{
					r=(r+1)%MAXN;
					q[r]=to;
					vst[to]=1;
				}
			}
		}
	}
	return 1;
}
int main()
{
	cin>>n;
	for(int i=1,x,y,z;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		y++;
		minn=min(minn,x);
		maxx=max(maxx,y);
		add(y,x,-z);
	}
	for(int i=1;i<=maxx;i++)add(0,i,0);
	for(int i=1;i<maxx;i++){add(i+1,i,0);add(i,i+1,1);}
	if(SPFA(0)==0)cout<<-1<<endl;
	else
	{
		for(int i=1;i<=maxx;i++)minn=min(minn,dis[i]);
		cout<<dis[maxx]-minn<<endl;
	}
	return 0;
}