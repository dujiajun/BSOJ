#include<iostream>
using namespace std;
struct edge{int to,next;}a[2005];
int n,h[2005],cnt,ans=1<<29,p,f[200][200];
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt; 
}
void dp(int x,int fa) 
{
	int to;
	for(int i=h[x];i;i=a[i].next)
	if(a[i].to!=fa)
	{
		to=a[i].to;
		dp(to,x);
		for(int j=p;j>=1;j--)
		for(int k=1;k<j;k++)
		f[x][j]=min(f[x][j],f[x][j-k]+f[to][k]-2);
	}
}
int main()
{
	cin>>n>>p;
	for(int i=2,x,y;i<=n;i++)
	{
		cin>>x>>y;
		add(x,y);
		add(y,x);
		f[x][1]++;f[y][1]++;
	}
	for(int i=1;i<=n;i++)
	for(int j=2;j<=p;j++)f[i][j]=1<<29;
	dp(1,0);
	for(int i=1;i<=n;i++)ans=min(ans,f[i][p]);
	cout<<ans<<endl;
	return 0;
}
/*
11 6
1 2
1 3
1 4
1 5
2 6
2 7
2 8
4 9
4 10
4 11
*/