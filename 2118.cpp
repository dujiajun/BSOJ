#include<iostream>
#include<cstring>
using namespace std;
struct edge{int to,next,v;}a[3005];
int n,m,p,c[1005],sum,ans=1<<29,cnt,h[1005],pos[1005],d[1005],dis[1005],vst[1005];
inline void add(int x,int y,int z)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].v=z;
	h[x]=cnt;
}
void heap_up(int x)
{
	while(x>1&&dis[d[x]]<dis[d[x/2]])
	{
		swap(d[x],d[x/2]);
		swap(pos[d[x]],pos[d[x/2]]);
		x/=2;
	}
}
void heap_down(int x)
{
	int i=x,j;
	while(i*2<=d[0])
	{
		if(i*2==d[0]||dis[d[i*2]]<dis[d[i*2+1]])j=i*2;
		else j=i*2+1;
		if(dis[d[i]]<dis[d[j]])return;
		swap(d[i],d[j]);
		swap(pos[d[i]],pos[d[j]]);
		i=j;
	}
}
int del()
{
	int tmp=d[1];
	d[1]=d[d[0]--];
	pos[d[1]]=1;
	heap_down(1);
	return tmp;
}
void dijkstra(int st)
{
	for(int i=1;i<=n;i++)
	{
		d[i]=i;
		pos[i]=i;
		dis[i]=1<<29;
		vst[i]=0;
	}
	d[0]=n;dis[st]=0;
	heap_up(pos[st]);
	int x,to;
	for(int i=1;i<=n;i++)
	{
		x=del();vst[x]=1;
		for(int j=h[x];j;j=a[j].next)
		{
			to=a[j].to;
			if(!vst[to]&&dis[to]>dis[x]+a[j].v)
			{
				dis[to]=dis[x]+a[j].v;
				heap_up(pos[to]);
			}
		}
	}
}
int main()
{
	cin>>m>>n>>p;
	for(int i=1,x;i<=m;i++)
	{
		cin>>x;
		c[x]++;
	}
	for(int i=1,x,y,z;i<=p;i++)
	{
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=n;i++)
	{
		memset(vst,0,sizeof(vst));
		memset(d,0,sizeof(h));
		dijkstra(i);sum=0;
		for(int j=1;j<=n;j++)sum+=c[j]*dis[j];
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
} 
/*
3 4 5
2
3
4
1 2 1
1 3 5
2 3 7
2 4 3
3 4 5
*/