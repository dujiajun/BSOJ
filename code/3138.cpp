#include<iostream>
using namespace std;
struct edge{int to,next,v;}a[20005]={0};
int h[10005]={0},cnt=0,n,m,q[2000500]={0},dis[10005]={0},vst[10005]={0},ans=1<<29;
void add(int x,int y,int z)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].v=z;
	h[x]=cnt;
}
void SPFA(int x)
{
	int l=0,r=0;
   	for(int i=1;i<=n;i++)dis[i]=1<<29;
   	for(int i=h[x];i;i=a[i].next)
   	{
	   	dis[a[i].to]=min(dis[a[i].to],a[i].v);
    	q[++r]=a[i].to;vst[a[i].to]=1;
   	}
   	while(l<r)
    {
       	l++;
		int i=q[l];vst[i]=0;
       	for(int j=h[i];j;j=a[j].next)
        if(dis[a[j].to]>dis[i]+a[j].v)
        {
        	dis[a[j].to]=dis[i]+a[j].v;
            if(!vst[a[j].to])
			{
				vst[a[j].to]=1;
				r++;
				q[r]=a[j].to;
			}
        }
   	}
 	ans=min(ans,dis[x]);
}
int main()
{
    cin>>n>>m;
    for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		add(x,y,z);
	}
    for(int i=1;i<=n;i++)SPFA(i);
    cout<<ans<<endl;
    return 0;
}