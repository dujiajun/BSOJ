#include<iostream>
#include<cstring>
using namespace std;
struct edge{int to,next;}b[400010];
struct edg{int a,b,v;}a[400010];
int n,m,maxx=0,l=0,r,mid,cnt=0,h[400010]={0},vst[400010]={0},bj;
void add(int x,int y)
{
	b[++cnt].to=y;
	b[cnt].next=h[x];
	h[x]=cnt;
}
void dfs(int x,int fa,int c)
{
	if(vst[x]){if(vst[x]!=c)bj=0;return;}
	vst[x]=c;
	for(int i=h[x];i;i=b[i].next)
	if(b[i].to!=fa)
	{
		dfs(b[i].to,x,3-c);
	}
}
bool check(int x)
{
	memset(vst,0,sizeof(vst));
	memset(h,0,sizeof(h));
	for(int i=1;i<=m;i++)
	if(a[i].v>x)
	{
		add(a[i].a,a[i].b);
		add(a[i].b,a[i].a);
	}
	bj=1;
	for(int i=1;i<=n;i++)
	if(!vst[i])
	{
		dfs(i,0,1);
		if(!bj)return 0;
	}
	return 1;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].v);
		maxx=max(maxx,a[i].v);
	}
	r=maxx;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<r+1<<endl;
	return 0;
}
/*
4 6
1 4 2534
2 3 3512
1 2 28351
1 3 6618
2 4 1805
3 4 12884
*/