#include<iostream>
#include<cstring>
using namespace std;
const int INF=1<<28;
struct edge{int to,next,f,op;}a[200005];
int cnt,h[605],l,w,n,px[605],py[605],maps[605][605],st,ed,tot,vst[605],dis[605],gap[605],ans;
int dist(int i,int j){return (px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]);}
void add(int x,int y,int z)
{
	a[++cnt].to=y;a[cnt].next=h[x];a[cnt].f=z;a[cnt].op=cnt+1;h[x]=cnt;
	a[++cnt].to=x;a[cnt].next=h[y];a[cnt].f=0;a[cnt].op=cnt-1;h[y]=cnt;
}
void dfs(int x)
{
	vst[x]=1;
	for(int i=0;i<=n+1;i++)if(maps[x][i]&&!vst[i])dfs(i);
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
	cin>>l>>w>>n;
	for(int i=1;i<=n;i++){cin>>px[i]>>py[i];}
	st=n+1;ed=0;
	for(int i=1;i<=n;i++)
	{
		if(py[i]<=100)maps[ed][i]=maps[i][ed]=1;
		if(w-py[i]<=100)maps[st][i]=maps[i][st]=1;
	}
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)if(dist(i,j)<=40000)maps[i][j]=maps[j][i]=1;
	dfs(st);
	if(vst[ed]==0)
	{
		cout<<0<<endl;
		return 0;
	}
	tot=n*2+2;st=n*2+1;ed=0;
	for(int i=1;i<=n;i++)add(i*2-1,i*2,1);
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	if(maps[i][j])
	{
		add(i*2,j*2-1,INF);
		add(j*2,i*2-1,INF);
	}
	for(int i=1;i<=n;i++)
	{
		if(maps[0][i])add(i*2,ed,INF);
		if(maps[i][n+1])add(st,i*2-1,INF);
	}
	gap[0]=tot;
	while(dis[st]<tot)ans+=sap(st,INF);
	cout<<ans<<endl;
	return 0;
}
/*
130 340 5
10 50
130 130
70 170
0 180
60 260
*/