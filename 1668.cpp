#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
using namespace std;
const int MAXN=205;
struct fck{double x,y;}nc[MAXN];
int vst[MAXN],prt[MAXN],prt1[MAXN],db[MAXN][MAXN]={0},n,m;
double map[MAXN][MAXN]={0},d[MAXN]={0},ans=1e100;
void init()
{
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>nc[i].x>>nc[i].y;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)map[i][j]=1e100;
	for(int j=1;j<=m;j++)
	{
		cin>>x>>y;
		map[x][y]=map[y][x]=sqrt((nc[x].x-nc[y].x)*(nc[x].x-nc[y].x)+(nc[x].y-nc[y].y)*(nc[x].y-nc[y].y));
	}
		
}
void dij()
{
	int k;
	double minn;
	memset(vst,0,sizeof(vst));
	for(int i=1;i<=n;i++)d[i]=1e100;
	d[1]=0;prt[1]=1;
	for(int i=1;i<=n;i++)
	{
		minn=1e100;
		for(int j=1;j<=n;j++)if(d[j]<minn&&!vst[j]){minn=d[j];k=j;}
		vst[k]=1;
		for(int j=1;j<=n;j++)
			if(d[k]+map[k][j]<d[j]&&!vst[j]&&!db[k][j])
			{
				d[j]=d[k]+map[k][j];
				prt[j]=k;
			}
	}
}
void sec()
{
	memcpy(prt1,prt,sizeof(prt));
	for(int i=n;i!=1;i=prt1[i])
	{
		db[i][prt1[i]]=db[prt1[i]][i]=1;
		dij();
		if(d[n]<ans)ans=d[n];
		db[i][prt1[i]]=db[prt1[i]][i]=0;
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;
}
int main()
{
	init();
	dij();
	sec();
	return 0;
}