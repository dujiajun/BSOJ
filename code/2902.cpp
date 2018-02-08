#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=1000001,INF=-1<<29;
int h[maxn],cnt=0,vst[maxn]={0},dis[maxn]={0},n,m,q[maxn]={0},usd[maxn]={0},st,ed;
struct edge{int to,next,v;}a[maxn*2];
void add(int x,int y,int v)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].v=v;
	h[x]=cnt;
}
int spfa(int v0)
{
	int l=0,r=1;
   	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[v0]=0;q[r]=v0;vst[v0]=1;
   	while(l<r)
   	{  
   		l=(l+1)%maxn;
      	int i=q[l];vst[i]=0;
      	for(int p=h[i];p;p=a[p].next)
      	{  
		  	int j=a[p].to;
         	if(dis[j]<dis[i]+a[p].v)
         	{  
			 	usd[j]++;
            	if(usd[j]>=n)return 0;
            	dis[j]=dis[i]+a[p].v;
            	if(!vst[j])
				{
					r=(r+1)%maxn;
					q[r]=j;
					vst[j]=1;
				}
         	}
      	}
   }
   return 1;
}
void init()
{
	cin>>n>>m;
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		add(x,y,z);
	}
	if(m<n-1)
	{
		cout<<-1;
		exit(0);
	}
}
int main()
{
 	init();
 	spfa(1);
 	if(dis[n]!=INF)cout<<dis[n];
 	else cout<<-1;
	return 0;
}
/*
4 7
1 2 68
1 3 19
1 4 66
2 3 23
3 4 65
3 2 57
4 1 68
*/