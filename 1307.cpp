#include<iostream>
using namespace std;
const int INF=1<<29;
int g[101][101],n,t,dist[101],vst[101]={0};
void dijkstra(int src)
{
	for(int i=0;i<n;i++)dist[i]=INF;
	dist[src]=0;
	for(int i=0;i<n;i++)
	{
		int maxx=INF,pos;
		for(int j=0;j<n;j++)
		if(dist[j]<maxx&&!vst[j]){maxx=dist[j];pos=j;}
		vst[pos]=1;
		for(int j=0;j<n;j++)
		if(g[pos][j]!=-1&&dist[j]>dist[pos]+g[pos][j])dist[j]=dist[pos]+g[pos][j];
	}
}
int main()
{
	cin>>n>>t;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)cin>>g[i][j];
	dijkstra(t);
	for(int i=0;i<n;i++)cout<<dist[i]<<" ";
	return 0;
}