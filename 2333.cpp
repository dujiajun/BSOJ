#include<iostream>
using namespace std;
int f[101][101]={0},w[101][101]={0},k,m,x,y,v,n;
void init()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>v;
		for(int j=1;j<=x;j++)
		for(int p=y;p<=m;p++)w[j][p]+=v; 
	}
	cin>>k;
}
void dp()
{
	for(int i=0;i<=k;i++)
	for(int j=0;j<=m;j++)f[i][j]=-0x7fffffff/2;
	f[0][0]=0;
	for(int i=1;i<=k;i++)
	for(int j=i;j<=m;j++)
	for(int p=0;p<j;p++)
		f[i][j]=max(f[i][j],f[i-1][p]+w[p+1][j]);
	cout<<f[k][m];
}
int main()
{
	init();
	dp();
	return 0;
}
/*
3
2
1 2 2
2 3 3
2
*/