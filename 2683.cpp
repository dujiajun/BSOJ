#include<iostream>
using namespace std;
struct edge{int to,next,f,op;}a[200005];
int cnt,h[505],n,f,d,gap[505],dis[505],st,ed,tot,ans;
void addedge(int x,int y,int z)
{
	a[++cnt].to=y;a[cnt].next=h[x];a[cnt].f=z;a[cnt].op=cnt+1;h[x]=cnt;
	a[++cnt].to=x;a[cnt].next=h[y];a[cnt].f=0;a[cnt].op=cnt-1;h[y]=cnt;
}
int sap(int x,int fl)
{
	if(x==ed)return fl;
	int tmp=fl,dt;
	for(int i=h[x];i;i=a[i].next)
	if(a[i].f>0&&dis[x]==dis[a[i].to]+1)
	{
		dt=sap(a[i].to,min(tmp,a[i].f));
		tmp-=dt;
		a[i].f-=dt;
		a[a[i].op].f+=dt;
		if(dis[st]==tot||tmp==0)return fl-tmp;
	}
	if(--gap[dis[x]]==0)dis[st]=tot;
	else ++gap[++dis[x]];
	return fl-tmp;
}
int main()
{
	cin>>n>>f>>d;
	tot=n+n+f+d+2;st=0;ed=n+n+f+d+1;
	for(int i=1,x,y,xx;i<=n;i++)
	{
		cin>>x>>y;addedge(i*2-1,i*2,1);
		for(int j=1;j<=x;j++)
		{
			cin>>xx;
			addedge(n+n+xx,i*2-1,1);
		}
		for(int j=1;j<=y;j++)
		{
			cin>>xx;
			addedge(i*2,n+n+f+xx,1);
		}
	}
	for(int i=1;i<=f;i++)addedge(st,i+n+n,1);
	for(int i=1;i<=d;i++)addedge(i+n+n+f,ed,1);
	gap[0]=tot;
	while(dis[st]<tot)ans+=sap(st,1<<28);
	cout<<ans<<endl;
	return 0;
}
/*
4 3 3
2 2 1 2 3 1
2 2 2 3 1 2
2 2 1 3 1 2
2 1 1 3 3
*/