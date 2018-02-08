#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
struct point{int x,y;}p[1005];
int n;
double map[1005][1005],ans,minn=1<<29,dis[1005];
bool vst[1005];
inline double dist(point p1,point p2){return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));}
void prim(int v0)
{
	int now;
	for(int i=1;i<=n;i++)dis[i]=1<<29;
	dis[v0]=0;vst[v0]=0;
	for(int i=1;i<=n;i++)
	{
		minn=1<<29;
		for(int j=1;j<=n;j++)if(!vst[j]&&dis[j]<minn){minn=dis[j];now=j;}
		vst[now]=1;
		ans+=dis[now];
		for(int j=1;j<=n;j++)
		if(!vst[j]&&map[now][j]<dis[j])dis[j]=map[now][j];
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;
}
int  main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i].x>>p[i].y;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)map[i][j]=dist(p[i],p[j]);
	prim(1);
	return 0;
}