#include<iostream>
using namespace std;
struct edge{int to,next;}a[400005];
int n,cnt,h[200005],c,up[200005],down1[200005],down2[200005],to[200005],ans=0;
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
		if(to[fa]==x)up[x]=max(up[fa],down2[fa])+1;
		else up[x]=max(up[fa],down1[fa])+1;
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
	for(int i=2,x,y;i<=n;i++)
	{
		scanf("%d%d",&x,&y);x++;y++;
		add(x,y);add(y,x);
	}
	down(1,0);
	treeup(1,0);
	for(int i=1;i<=n;i++)ans=max(ans,down1[i]+up[i]);
	for(int i=1;i<=n;i++)if(up[i]+down1[i]==ans||down1[i]+down2[i]==ans||up[i]+down2[i]==ans)printf("%d\n",i-1);
	return 0;
}
/*
10
0 1
0 2
0 4
0 6
0 7
1 3
2 5
4 8
6 9
*/