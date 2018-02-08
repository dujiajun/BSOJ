#include<iostream>
using namespace std;
struct edge{int to,next;}a[20005];
int n,cnt,h[10005],f[10005][3];
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void treedp(int x,int fa)
{
	int minn,cha=1<<29;
	f[x][0]=0;
	f[x][1]=0;
	f[x][2]=1;
	for(int i=h[x];i;i=a[i].next)
	if(a[i].to!=fa)
	{
		int to=a[i].to;
		treedp(to,x);
		minn=min(f[to][0],f[to][2]);
		f[x][0]+=minn;
		f[x][1]+=minn;
		f[x][2]+=min(f[to][1],f[to][2]);
		cha=min(cha,f[to][2]-minn);
	}
	f[x][0]+=cha;
}
int main()
{
	cin>>n;
	for(int i=2,x,y;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	treedp(1,1);
	cout<<min(f[1][0],f[1][2]);
	return 0;
}