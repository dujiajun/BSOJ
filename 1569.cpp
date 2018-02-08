#include<iostream>
using namespace std;
struct edge{int to,next;}a[40000];
int n,v[16005]={0},h[16005]={0},cnt=0,f[16005]={0},u[16005]={0},maxx=-0x7fffffff/2;
void add(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1,a,b;i<=n-1;i++)
	{
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
}
void dp(int x)
{
	f[x]=v[x],u[x]=1;
	for(int i=h[x];i;i=a[i].next)
		if(u[a[i].to]==0)
		{
			dp(a[i].to);
			f[x]+=max(f[a[i].to],0);
		}
}
int main()
{
	init();
	dp(1);
	for(int i=1;i<=n;i++)maxx=max(maxx,f[i]);
	cout<<maxx;
	return 0;
} 
/*
7
-1 -1 -1 1 1 1 0
1 4
2 5
3 6
4 7
5 7
6 7
*/