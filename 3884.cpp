#include <iostream>
#include <cstring>
using namespace std;
const int INF=1<<30,Maxn=10005;
struct Edge {int to,next,v;}w[100005];
int N,M,K,ans=INF,P[6]={0},cnt=0,H[Maxn]={0},Ha[Maxn]={0},
	vst[Maxn]={0},dis[6][10005]={0},
	Use[6]={0},od[6]={0},que[Maxn];
void AddEdge(int x,int y,int v)
{
	cnt++;
	w[cnt].to=y;
	w[cnt].v=v;
	w[cnt].next=H[x];
	H[x]=cnt;
}
void init()
{
	int x,y,v;
	cin>>N>>M>>K;
	for(int i=1;i<=K;i++) {cin>>P[i];Ha[P[i]]=1;}
	for(int i=1;i<=M;i++)
	{
		cin>>x>>y>>v;
		AddEdge(x,y,v);
		AddEdge(y,x,v);
	}
}
void SPFA(int k)
{
	int x,y;
	memset(vst,0,sizeof(vst));
	for(int i=1;i<=N;i++)dis[k][i]=INF;
	vst[P[k]]=1,dis[k][P[k]]=0;
    int head=0,tail=1;
    que[tail]=P[k];
	while(head!=tail)
	{
	    head=(head+1)%Maxn;
        x=que[head];
	    vst[x]=0;
		for(int i=H[x];i;i=w[i].next)
		{
			y=w[i].to;
			if(dis[k][y]>dis[k][x]+w[i].v)
			{
				dis[k][y]=dis[k][x]+w[i].v;
				if(vst[y]) continue;
				vst[y]=1;
				tail=(tail+1)%Maxn;
                que[tail]=y;                      				
			}
		}
	}
}
void Cal()
{
 	int minn=INF; 
 	for(int i=1;i<=N;i++)
    	if(!Ha[i])minn=min(minn,dis[od[1]][i]+dis[od[K]][i]);
 	for(int i=1;i<K;i++)
   	minn+=dis[od[i]][P[od[i+1]]];
 	ans=min(ans,minn);
}
void DFS(int dp)
{
	if(dp==K+1){Cal();return;}
	for(int i=1;i<=K;i++)
	{
		if(Use[i])continue;
		od[dp]=i;Use[i]=1;
		DFS(dp+1);
		od[dp]=0;Use[i]=0;
	}
}
void Solve()
{
	for(int i=1;i<=K;i++)SPFA(i);
	DFS(1);
    cout<<ans<<endl;
}
int main()
{
	init();
	Solve();
	return 0;
}