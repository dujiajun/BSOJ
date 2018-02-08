#include<iostream>
using namespace std;
struct edge{int to,next,f,p;}a[40005];
int cnt,n,m,h[205],dis[205],gap[205],ans;
void add(int x,int y,int z)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].f=z;
	h[x]=cnt;
	a[cnt].p=cnt%2?cnt+1:cnt-1;
}
int sap(int x,int fl)
{
	if(x==n)return fl;
	int tmp=fl,to,dt;
	for(int i=h[x];i;i=a[i].next)
	if(a[i].f>0&&dis[x]==dis[a[i].to]+1)
	{
		dt=sap(a[i].to,min(a[i].f,tmp));
		tmp-=dt;
		a[i].f-=dt;
		a[a[i].p].f+=dt;
		if(dis[1]==n||tmp==0)return fl-tmp;
	}
	if(--gap[dis[x]]==0)dis[1]==n;
	else ++gap[++dis[x]];
	return fl-tmp;
}
int main()
{
	cin>>m>>n;
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,0);
	}
	gap[0]=n;
	while(dis[1]<n)ans+=sap(1,1<<29);
	cout<<ans<<endl;
	return 0;
 } 
/*
5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
*/ 