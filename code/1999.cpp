#include<iostream>
#include<iomanip>
using namespace std;
const int INF=1<<29;
struct edge{int to,next;double v;}a[2000005];
int n,m,vst[20005]={0},cnt=0,h[20005]={0},s,t;
double d[20005];
inline void add(int x,int y,int z)
{    
	cnt++;
	a[cnt].to=y;
	a[cnt].next=h[x];
	a[cnt].v=z;
	h[x]=cnt;
}
void dijkstra(int v0)
{ 
	double minn;int k; 
    for(int i=1;i<=n;i++)d[i]=0;
	d[v0]=1;
    for(int i=1;i<=n;i++)
    {    
	    minn=0;
		for(int j=1;j<=n;j++)
        if(!vst[j]&&minn<d[j]){k=j;minn=d[j];}
        vst[k]=1;
        for(int j=h[k];j;j=a[j].next)
        if(!vst[a[j].to]&&d[k]*(1-(a[j].v)/100)>d[a[j].to])d[a[j].to]=d[k]*(1-(a[j].v)/100);
    }
}
int main()
{   
	cin>>n>>m;
    for(int i=1,x,y,z;i<=m;i++)
    {
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
    cin>>s>>t;
    dijkstra(s);
    cout<<fixed<<setprecision(8)<<100/d[t]<<endl;
    return 0;
}
/*
3 3
1 2 1
2 3 2
1 3 3
1 3
*/