#include<iostream>
using namespace std;
const int INF(0x7fffffff/3);
const int maxn(200005);
int m,n,h[105],p[105],l[105],x,v,cnt,q[maxn],dis[105],vst[105],ans=INF;
struct star{int to,next,v;}a[maxn];
void add(int x,int y,int v)
{   
	cnt++;
	a[cnt].to=y;
    a[cnt].v=v;
    a[cnt].next=h[x];
    h[x]=cnt;
}
void SPFA(int xx)
{   
	for(int i=1;i<=n;i++){dis[i]=INF;vst[i]=0;}
    vst[1]=1;dis[1]=0;q[1]=1;
    int ll=0,r=1,u,to;
    while(ll!=r)
    {   
		ll=(ll+1)%maxn;
        u=q[ll];
        vst[u]=0;
        for(int i=h[u];i;i=a[i].next)
        {   
			to=a[i].to;
            if(dis[u]+a[i].v<dis[to]&&m+xx>=l[to]&&l[to]>=xx)
            {  
				dis[to]=dis[u]+a[i].v;
               	if(!vst[to]){r=(r+1)%maxn;q[r]=to;vst[to]=1;}
            }
        }
    }
    for(int i=1;i<=n;i++)
		if(m+xx>=l[i]&&l[i]>=xx&&dis[i]+p[i]<ans)
			ans=dis[i]+p[i];
}
void init()
{
	int xx;
	cin>>m>>n;
    for(int i=1;i<=n;i++)
    {   
		cin>>p[i]>>l[i]>>xx;
        for(int j=1;j<=xx;j++){cin>>x>>v;add(i,x,v);}
    }
}
int main()
{   
	init();
    for(int i=l[1]-m;i<=l[1];i++)SPFA(i);
    cout<<ans<<endl;
    return 0;
}
