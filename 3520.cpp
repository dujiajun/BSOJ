#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
struct edge{int to,next;}a[100005];
int n,m,cnt,h[205],s,map[205][205],d[205],prt[205],dis[205],q[40005];
double ps[205][205],f[205][205],maxx;
bool vst[205];
inline void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void SPFA(int st)
{
	int l=1,r=1;
	for(int i=1;i<=n;i++)dis[i]=1<<29;
	q[1]=st;vst[st]=1;dis[st]=0;
	while(l<=r)
	{
		int x=q[l];vst[x]=0;
		for(int i=1;i<=n;i++)
		if(map[x][i])
		{
			if(dis[i]>dis[x]+map[x][i])
			{
				dis[i]=dis[x]+map[x][i];
				prt[i]=x;
				if(!vst[i]){q[++r]=i;vst[i]=1;}
			}
		}
		l++;
	}
}
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)map[i][j]=1<<29;
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		map[x][y]=z;map[y][x]=z;
	}
	cin>>s;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=s;j++)scanf("%lf",&ps[i][j]);
}
void treedp(int x,double dp)
{
	double tmp=dp/d[x];
	for(int i=h[x];i;i=a[i].next)treedp(a[i].to,tmp);
	for(int i=h[x];i;i=a[i].next)
	{
		for(int j=s;j>=1;j--)
		for(int k=1;k<=j;k++)f[x][j]=max(f[x][j],f[a[i].to][k]+f[x][j-k]);
	}
	for(int i=s;i>=1;i--)
	for(int j=1;j<=i;j++)
	f[x][i]=max(f[x][i],ps[x][j]*dp+(1-ps[x][j])*f[x][i-j]);
}
int main()
{
	init();
	SPFA(1);
	for(int i=2;i<=n;i++){add(prt[i],i);d[prt[i]]++;}
	memset(vst,0,sizeof(vst));memset(prt,0,sizeof(prt));
	treedp(1,1);
	cout<<fixed<<setprecision(4)<<f[1][s]<<endl;
	return 0;
}
/*
4 4
1 2 1
1 3 2
2 4 3
3 4 1
2
0.01 0.1
0.5 0.8
0.5 0.8
0.7 0.9
*/