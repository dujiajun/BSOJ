#include<iostream>
using namespace std;
struct edge{int to,next;}a[20005];
int n,cnt,h[10005],c,up[10005],down1[10005],down2[10005],to[10005],ans=1<<29;
inline void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void treeup(int x,int fa)
{
	if(fa!=0)
	{
		if(to[fa]==x)
		{
			if(up[fa]>down2[fa])up[x]=up[fa]+1;
			else up[x]=down2[fa]+1;
		}
		else
		{
			if(up[fa]>down1[fa])up[x]=up[fa]+1;
			else up[x]=down1[fa]+1;
		}
	}
	for(int i=h[x];i;i=a[i].next)if(a[i].to!=fa)treeup(a[i].to,x);
}
void down(int x,int fa)
{
	for(int i=h[x];i;i=a[i].next)
	if(a[i].to!=fa)
	{
		down(a[i].to,x);
		if(down1[a[i].to]+1>down1[x])
		{
			down2[x]=down1[x];
			down1[x]=down1[a[i].to]+1;
			to[x]=a[i].to;
		}
		else if(down1[a[i].to]+1>down2[x])down2[x]=down1[a[i].to]+1;
	}
}
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&c);
		add(i,c);add(c,i);
	}
	down(1,0);
	treeup(1,0);
	for(int i=1;i<=n;i++)
	{
		if(up[i]>down1[i]&&up[i]<ans)ans=up[i];
		if(up[i]<=down1[i]&&down1[i]<ans)ans=down1[i];
	}
	for(int i=1;i<=n;i++)if(up[i]==ans||down1[i]==ans)printf("%d ",i);
	return 0;
}