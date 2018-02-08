#include<iostream>
#include<cstring>
using namespace std;
struct node {int next,to;}a[200005];
int f[100005][25],c[100005],h[100005],cnt=0,k,n;
inline void add(int x,int y) 
{	
	a[++cnt].next=h[x];
	a[cnt].to=y;
	h[x]=cnt;
}
void dp1(int x,int fa)
{
	int to;
	for(int i=0;i<=k;i++)f[x][i]=c[x];
	for(int i=h[x];i;i=a[i].next)
	if(a[i].to!=fa)
	{
		to=a[i].to;
		dp1(to,x);
		for(int j=0;j<k;j++)f[x][j+1]+=f[to][j];
	}
}
void dp2(int x,int fa)
{
	int to;
	for(int i=h[x];i;i=a[i].next)
	if(a[i].to!=fa)
	{
		to=a[i].to;
		for(int j=k;j>=1;j--)
		{
		    f[to][j]+=f[x][j-1];
		    if(j>=2)f[to][j]-=f[to][j-2];
		}
		dp2(to,x);
	}
}
int main()
{
	cin>>n>>k;
    for(int i=1,x,y;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    dp1(1,0);
    dp2(1,0);
    for(int i=1;i<=n;i++)printf("%d\n",f[i][k]);
    return 0;
}
