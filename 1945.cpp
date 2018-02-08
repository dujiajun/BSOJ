#include<iostream>
using namespace std;
int n,q,e[105][105]={0},l[105]={0},r[105]={0},f[105][105]={0},app[105]={0};
void init()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			e[i][j]=-100;
	for(int i=1,x,y,z;i<=n-1;i++)
	{
		cin>>x>>y>>z;
		e[x][y]=e[y][x]=z;
	}
}
void build(int x)
{
	for(int i=1;i<=n;i++)
	if(e[x][i]>-100)
	{
		l[x]=i;
		app[i]=e[x][i];
		e[x][i]=e[i][x]=-100;
		build(i);
		break;
	}
	for(int i=1;i<=n;i++)
	if(e[x][i]>-100)
	{
		r[x]=i;
		app[i]=e[x][i];
		e[x][i]=e[i][x]=-100;
		build(i);
		break;
	}
}
int dp(int i,int j)
{
	if(j==0)return 0;
	if(l[i]==0&&r[i]==0)return app[i];
	if(f[i][j]>0)return f[i][j];
	for(int k=0;k<=j-1;k++)
		f[i][j]=max(f[i][j],dp(l[i],k)+dp(r[i],j-k-1)+app[i]);
	return f[i][j];
}
int main()
{
	init();
	build(1);
	cout<<dp(1,1+q);
	return 0;
}
/*
5 2
1 3 1
1 4 10
2 3 20
3 5 20
*/