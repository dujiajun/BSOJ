#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct edge{int to,next,v;}a[200005];
int n,h[100005],cnt,c[100005];
long long ans=(1ll)<<62,dis[100005],f[100005][2];//
inline void add(int x,int y,int z)
{
	a[++cnt].to=y;
	a[cnt].v=z;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void dp1(int x,int fa)
{
	f[x][0]=0;f[x][1]=c[x];int to;
	for(int i=h[x];i;i=a[i].next)
	if(a[i].to!=fa)
	{
		to=a[i].to;
		dp1(to,x);
		f[x][0]+=f[to][0]+f[to][1]*a[i].v;
		f[x][1]+=f[to][1];
	}
}
void dp2(int x,int fa)
{
	int to;
	for(int i=h[x];i;i=a[i].next)
	if(a[i].to!=fa)
	{
		to=a[i].to;
		f[to][0]+=(f[x][1]-f[to][1])*a[i].v+(f[x][0]-f[to][0])-f[to][1]*a[i].v;
		f[to][1]+=f[x][1]-f[to][1];
		dp2(to,x);
	}
}
int main()
{
//	freopen("party.in","r",stdin);
//	freopen("party.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1,x,y,z;i<=n-1;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dp1(1,0);
	dp2(1,0);
	for(int i=1;i<=n;i++)ans=min(ans,f[i][0]);
	cout<<ans<<endl;
	return 0;
}
/*
5
1
1
0
0
2
1 3 1
2 3 2
3 4 3
4 5 3
*/