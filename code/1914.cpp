#include<iostream>
#include<cstring>
using namespace std;
const int INF=0x7fffffff/2;
int n,m,a,b,c,map[1001][1001],g1[1005],g2[1005],d1[1001],d2[1001],vst[1005]={0};
void init()
{
	int x,y,z;
	cin>>n>>m>>a>>b>>c;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		map[x][y]=map[y][x]=z;
	}
}
void solve(int s,int d[],int g[])
{
	memset(vst,0,sizeof(vst));
	for(int i=1;i<=n;i++)d[i]=INF;
	d[s]=0;g[s]=1;
	for(int i=1;i<=n;i++)
	{
		int minn=INF,k;
		for(int j=1;j<=n;j++)
			if(vst[j]==0&&d[j]<minn){minn=d[j];k=j;}
		vst[k]=1;
		for(int j=1;j<=n;j++)
			if(vst[j]==0&&map[k][j])
			{
				if(d[j]==d[k]+map[k][j])g[j]+=g[k];
				if(d[j]>d[k]+map[k][j]){g[j]=g[k];d[j]=d[k]+map[k][j];}
			}
	}
}
int main()
{
	init();
	solve(a,d1,g1);
	solve(b,d2,g2);
	if(d1[c]+d2[c]==d1[b])cout<<g1[c]*g2[c]<<endl;
	else cout<<0<<endl;
	return 0;
}