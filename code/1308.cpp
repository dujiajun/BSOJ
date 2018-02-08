#include<iostream>
using namespace std;
const int maxn=100001,INF=1<<29;
int h[maxn],cnt=0,vst[maxn]={0},dis[maxn]={0},n,m,q[maxn]={0},usd[maxn]={0},st,ed;
struct edge{int to,next;}a[maxn*2];
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
int spfa(int v0)
{
	int l=0,r=1;
   	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[v0]=0;q[r]=v0;vst[v0]=1;
   	while(l<r)
   	{  
   		l=(l+1)%maxn;
      	int i=q[l];vst[i]=0;
      	for(int p=h[i];p;p=a[p].next)
      	{  
		  	int j=a[p].to;
         	if(dis[j]>dis[i]+1)
         	{  
            	dis[j]=dis[i]+1;
            	if(!vst[j])
				{
					r=(r+1)%maxn;
					q[r]=j;
					vst[j]=1;
				}
         	}
      	}
   }
   return 1;
}
int main()
{
 	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		cin>>x>>y;
		add(x,y);
	}
	cin>>st>>ed;
 	spfa(st);
	if(dis[ed]!=1<<29)cout<<dis[ed]-1<<endl;
	else cout<<"no answer!"<<endl;
	return 0;
}