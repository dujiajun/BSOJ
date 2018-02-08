#include<iostream>
using namespace std;
const int INF=1<<29,maxn=2005;
struct edge{int to,next,v;}a[maxn*5];
int n,m,s,h[maxn]={0},cnt=0,dis[maxn]={0},vst[maxn]={0},usd[maxn]={0},q[maxn*100]={0};
void add(int x,int y,int v)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].v=v;
	h[x]=cnt;
}
int spfa(int v0)
{
	int l=1,r=1;
	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[v0]=0;vst[v0]=1;q[l]=v0;
	while(l<=r)
	{
		int i=q[l];vst[i]=0;
		for(int p=h[i];p;p=a[p].next)
		{
			int to=a[p].to;
			if(dis[to]>dis[i]+a[p].v)
			{
				usd[to]++;
				if(usd[to]>n)return 0;
				dis[to]=dis[i]+a[p].v;
				if(!vst[to])
				{
					r++;
					q[r]=to;
					vst[to]=1;
				}
			}
		}
		l++;
	}
	for(int i=1;i<=n;i++)if(dis[i]==INF)return 0;
	return 1;
}
void init()
{
	cin>>n>>m;s=n+1;
	for(int i=1;i<=n;i++)add(s,i,0);
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		add(y,x,z);
	}
}
void solve()
{
	int k=0;
	if(spfa(s))
	{
		for(int i=1;i<=n;i++)k=min(k,dis[i]);
		if(k<0)for(int i=1;i<=n;i++)dis[i]-=k;
		for(int i=1;i<=n;i++)cout<<dis[i]<<endl;
	}
	else cout<<"NO SOLUTION"<<endl;
}
int main()
{
	init();
	solve();
	return 0;
}
/*
5 8
1 2 0 
1 5 -1
2 5 1
3 1 5
4 1 4
4 3 -1
5 3 -3
5 4 -3
*/