#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct edge{int to,next;}a[400005];
int n,K,cnt=0,f[200005]={0},b[200005]={0},h[200005]={0},v[200005]={0};
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void dfs(int x)
{
	int k;
	if(!h[x]){f[x]=v[x];return;}
	for(int i=h[x];i;i=a[i].next)
	{
		int to=a[i].to;
		dfs(to);
		if(f[to]>f[x]){f[x]=f[to];k=to;}
	}
	for(int i=h[x];i;i=a[i].next)
	{
		int to=a[i].to;
		if(to!=k)b[++b[0]]=f[to];
	}
	f[x]+=v[x];
}
int main()
{
	cin>>n>>K;
	for(int i=1,x;i<=n;i++)
	{
		scanf("%d%d",&x,&v[i]);
		add(x,i);
	}
	dfs(0);
	long long ans=0;
	b[++b[0]]=f[0];
	sort(b+1,b+b[0]+1);
	for(int i=1;i<=K;i++)ans+=b[b[0]-i+1];
	cout<<ans<<endl;
	return 0;
}
/*
8 2
0 1
1 1
2 100
2 100
0 1
5 1
6 2
6 2
*/