#include<iostream>
#include<cstdio>
using namespace std;
int a[101][101]={0},sum[101][101]={0},ans=0,m,n;
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
}
void ready()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			sum[i][j]=sum[i-1][j]+a[i][j];
}
void get(int s,int t,int l,int r,int &mx,int &mi)
{
	int p,q;
	mx=-0x7fffffff;mi=0x7fffffff;
	for(int i=s;i<=t;i++)
	for(int j=i;j<=t;j++)
	{
		p=0;q=0;
		for(int k=l;k<=r;k++)
		{
			if(p<0)p=sum[j][k]-sum[i-1][k];
			else p+=sum[j][k]-sum[i-1][k];
			if(q>0)q=sum[j][k]-sum[i-1][k];
			else q+=sum[j][k]-sum[i-1][k];
			mx=max(mx,p);
			mi=min(mi,q);
		}
	}
}
void dp()
{
	int a1,a2,b1,b2;
	ans=-0xfffffff;
	for(int k=1;k<=m-1;k++)
	{
		get(1,n,1,k,a1,a2);
		get(1,n,k+1,m,b1,b2);
		ans=max(ans,a1*b1);
		ans=max(ans,a2*b2);
	}
	for(int k=1;k<=n-1;k++)
	{
		get(1,k,1,m,a1,a2);
		get(k+1,n,1,m,b1,b2);
		ans=max(ans,a1*b1);
		ans=max(ans,a2*b2);
	}
}
int main()
{
	init();
	ans=0;
	ready();
	dp();
	cout<<ans<<endl;
	return 0;
}