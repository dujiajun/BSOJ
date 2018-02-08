#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1005,INF=0x7fffffff/2;
int n,m,op,dis[maxn]={0},dis2[maxn]={0},map[maxn][maxn]={0},ans=0,sum=0;
bool vst[maxn];
int Dijkstra_1(int st)
{
	memset(vst,0,sizeof(vst));
 	int k;
	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[st]=0;
	for(int i=1;i<=n;i++)
 	{
	 	int minn=INF;
 		for(int j=1;j<=n;j++)
  			if(!vst[j]&&minn>dis[j]){minn=dis[j];k=j;}
   		vst[k]=1;
 		for(int j=1;j<=n;j++)
  			if(map[j][k]&&!vst[j]&&dis[k]+map[j][k]<dis[j]) 
			  	dis[j]=dis[k]+map[j][k]; 
 	}
}
int Dijkstra_2(int st)
{
	memset(vst,0,sizeof(vst));
 	int k;
	for(int i=1;i<=n;i++)dis2[i]=INF;
 	dis2[st]=0;
	for(int i=1;i<=n;i++)
 	{
	 	int minn=INF;
 		for(int j=1;j<=n;j++)
  			if(!vst[j]&&minn>dis2[j]){minn=dis2[j];k=j;}
  		vst[k]=1;
  		for(int j=1;j<=n;j++)
        	if(map[k][j]&&!vst[j]&&dis2[k]+map[k][j]<dis2[j])
		 		dis2[j]=dis2[k]+map[k][j];
 }
}
int main()
{
 	cin>>n>>m>>op; 
 	for(int i=1,x,y,v;i<=m;i++)
  	{
	  	scanf("%d%d%d",&x,&y,&v);
    	if(!map[x][y])map[x][y]=v;
        else map[x][y]=min(map[x][y],v);
  	}
  	Dijkstra_1(op);
  	Dijkstra_2(op);
 	for(int i=1;i<=n;i++)
  	{
		sum=dis2[i]+dis[i];
   		ans=max(ans,sum); 
  	}
 	cout<<ans<<endl;
 	return 0;  
}