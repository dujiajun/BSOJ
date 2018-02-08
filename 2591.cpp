#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int n,a[100005]={0},f[100005][50]={0},g[100005][50]={0},q;
void pre()
{
	int t=log2(n);
	for(int i=1;i<=n;i++)f[i][0]=g[i][0]=a[i];
	for(int j=1;j<=t;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			g[i][j]=min(g[i][j-1],g[i+(1<<(j-1))][j-1]);
		}
}
int askmax(int l,int r)
{
	int t=log2(r-l+1);
	return max(f[l][t],f[r-(1<<t)+1][t]);	
}
int askmin(int l,int r)
{
	int t=log2(r-l+1);
	return min(g[l][t],g[r-(1<<t)+1][t]);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	pre();
	for(int i=1,x,y;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",askmax(x,y)-askmin(x,y));
	}
	return 0;
}
/*
6 3
1
7
3
4
2
5
1 5
4 6
2 2
*/