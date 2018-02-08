#include<iostream>
#include<cstring>
using namespace std;
const int INF=0x7fffffff/10,Maxn=50005;
struct list{int to,next,v;}a[500005];
int n,m,cnt=0,ans=INF;
int h[Maxn]={0},p[6]={0},dis[6][Maxn]={0},
	que[Maxn],od[6]={0},vst[Maxn]={0},used[6]={0};
void addedge(int x,int y,int v)
{
	cnt++;
	a[cnt].to=y;
	a[cnt].v=v;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void init()
{
	cin>>n>>m;
    for(int i=1;i<=5;i++)cin>>p[i];
    for(int i=1,x,y,v;i<=m;i++)
	{
       cin>>x>>y>>v;
       addedge(x,y,v);
       addedge(y,x,v);
	}
}
void cal()
{
	int minn=INF;
	minn=min(minn,dis[od[1]][1]);
	minn=min(minn,dis[od[5]][1]);
    for(int i=1;i<5;i++)
        minn+=dis[od[i]][p[od[i+1]]];
    ans=min(minn,ans);
}
void dfs(int dp)
{
	if(dp==6){cal();return;}
	for(int i=1;i<=5;i++)
	{
		if(used[i])continue;
		od[dp]=i;used[i]=1;
		dfs(dp+1);
		od[dp]=0;used[i]=0;
	}
}
void SPFA(int st)
{
    memset(vst,0,sizeof(vst));
    for(int i=1;i<=n;i++)dis[st][i]=INF; 
	dis[st][p[st]]=0;
	vst[p[st]]=1;
	int head=0,tail=1,x,y;
	que[tail]=p[st];
	while(head!=tail)
	{
		head=(head+1)%Maxn;
		x=que[head];
		vst[x]=0;
		for(int i=h[x];i;i=a[i].next)
		{
			y=a[i].to;
			if(dis[st][y]>dis[st][x]+a[i].v)
			{
				dis[st][y]=dis[st][x]+a[i].v;
				if(vst[y])continue;
				vst[y]=1;
				tail=(tail+1)%Maxn;
				que[tail]=y;
			}
		}
	}
}
void solve()
{
	for(int i=1;i<=5;i++)SPFA(i);
    dfs(1);
    cout<<ans<<endl;
}
int main()
{
    init();
    solve();
	return 0;
}
