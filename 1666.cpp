#include<iostream>
using namespace std;
const int maxn=100001,INF=1<<29;
int h[maxn],cnt=0,vst[maxn]={0},dis[maxn]={0},n,m,q[maxn]={0},usd[maxn]={0},st;
struct edge{int to,next,v;}a[maxn*2];
void add(int x,int y,int v)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].v=v;
	h[x]=cnt;
}
int spfa(int v0)
{
	int l=0,r=0;
   	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[v0]=0;
   	r++;q[r]=v0;vst[v0]=1;
   	while(l!=r)
   	{  
	   	l=(l+1)%maxn;
      	int i=q[l];vst[i]=0;
      	for(int p=h[i];p!=0;p=a[p].next)
      	{  
		  	int j=a[p].to;
         	if(dis[j]>dis[i]+a[p].v)
         	{  
			 	usd[j]++;
            	if(usd[j]>=n)return 0;
            	dis[j]=dis[i]+a[p].v;
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
void init()
{
	cin>>n>>m>>st;
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		add(x,y,z);
	}
}
int main()
{
 	init();
 	if(spfa(st)==0)cout<<-1<<endl;
 	else 
 		for(int i=1;i<=n;i++)
 		{
 			if(dis[i]==INF)cout<<"NoPath"<<endl;
			else cout<<dis[i]<<endl;
 		}
	return 0;
}
/*
6 8 1
1 3 4
1 2 6
3 4 -7
6 4 2
2 4 5
3 6 3
4 5 1
3 5 4
*/