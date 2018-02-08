#include<iostream>
#include<cstring>
using namespace std;
struct edge{int to,next;}a[400005];
int n,cnt,h[200005],maxx,st,d[200005];
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void dfs(int x,int fa,int dp)
{
	d[x]=dp;if(d[x]>maxx){maxx=d[x];st=x;}
	for(int i=h[x];i;i=a[i].next)
	if(a[i].to!=fa)dfs(a[i].to,x,dp+1);
}
int main()
{
	cin>>n;
	for(int i=2,x,y;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(0,-1,0);
	memset(d,0,sizeof(d));
	dfs(st,-1,0);
	cout<<maxx<<endl;
	return 0;
}