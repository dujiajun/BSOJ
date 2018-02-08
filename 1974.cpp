#include<iostream>
#include<algorithm> 
using namespace std;
const int INF=1<<29,MAXN=10005;
struct edge{int to,next,v;}a[MAXN*20];
int n,m,cnt=0;
int dis[MAXN],h[MAXN],q[MAXN];
bool vst[MAXN]={0};
void addedge(int x,int y,int z)
{  
   	a[++cnt].to=y;
   	a[cnt].next=h[x];
  	a[cnt].v=z;
   	h[x]=cnt;
}
void SPFA(int st)
{
	for(int i=1;i<=n;i++)dis[i]=INF;
	int l=0,r=1,x,to;
	dis[st]=0;vst[st]=1;q[1]=st;
	while(l<r)
	{
		x=q[(++l)%MAXN];vst[x]=0;
		for(int i=h[x];i;i=a[i].next)
		{
			to=a[i].to;
			if(dis[to]>dis[x]+a[i].v)
			{
				dis[to]=dis[x]+a[i].v;
				if(!vst[to])
				{
					r++;
					q[r%MAXN]=to;
					vst[to]=1;
				}
			}
		}
	}
}
int main()
{   
	int x,y,z;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
	{
      	scanf("%d%d%d",&x,&y,&z);
      	addedge(x,y,z);
      	//addedge(y,x,z);
    }
    cin>>x>>y;
    SPFA(x);
    if(dis[y]==INF)cout<<"No Solution!"<<endl;
    else cout<<dis[y]<<endl;
    return 0;
}
/*
4 4
1 2 3
2 4 10
1 3 5
3 4 5
1 4
*/