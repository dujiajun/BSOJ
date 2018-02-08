#include<iostream>
using namespace std;
struct edge{int to,next,op,f;}a[80005];
int cnt,h[505],gap[505],dis[505],n,m,ans,st,ed,tot;
void add(int x,int y,int z)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].f=z;
	a[cnt].op=cnt&1?cnt+1:cnt-1;
	h[x]=cnt;
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
	else --gap[++dis[x]];
	return fl-tmp;
}
int main()
{
	cin>>n>>m;
	for(int i=1,x;i<=n;i++)
	{
		while(1)
		{
			cin>>x;
			if(x==0)break;
			add(i,n+x,1);
			add(n+x,i,0);
		}
	}
	st=0;ed=n+m+1;tot=n+m+2;
	for(int i=1;i<=n;i++)
	{
		add(st,i,1);
		add(i,st,0);
	}
	for(int i=1;i<=m;i++)
	{
		add(i+n,ed,1);
		add(ed,i+n,0);
	}
	gap[0]=tot;
	while(dis[st]<tot)ans+=sap(st,1<<28);
	cout<<ans<<endl;
	return 0;
} 
/*
4 4
1 2 0
1 2 0
1 2 0
1 2 3 4 0
*/