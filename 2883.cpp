#include<iostream>
using namespace std;
const int INF=1<<29;
int map[505][505]={0},n,m,s,t,p[505],dis[505]={0},vst[505]={0};
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		map[i][j]=INF;
	for(int i=1,a,b,v;i<=m;i++)
	{
		cin>>a>>b>>v;
		map[a][b]=v;
	}
	cin>>s>>t;
}
int dij(int x,int y)
{
	int min=INF,k;
	for(int i=1;i<=n;i++)
	{
		dis[i]=map[x][i];
		if(dis[i]!=INF)p[i]=s;
	}
	dis[x]=0;vst[x]=1;
	for(int i=1;i<=n;i++)
	{
		min=INF;
		for(int j=1;j<=n;j++)
		if(!vst[j]&&dis[j]<min){min=dis[j];k=j;}
		vst[k]=1;
		for(int j=1;j<=n;j++)
		{
			if(!vst[j]&&dis[j]>dis[k]+map[k][j])
			{
				dis[j]=map[k][j]+dis[k];
				p[j]=k;
			}
		}
	}
	return dis[y];
}
void out(int x)
{
	if(x)
	{
		out(p[x]);
		cout<<x<<" ";	
	}
}
int main()
{
	init();
	cout<<dij(s,t)<<endl;
	out(t);
	return 0;
}
/*
5 7
1 2 10
1 4 30
1 5 100
2 3 50
3 5 10
4 3 20
4 5 60
1 5
*/