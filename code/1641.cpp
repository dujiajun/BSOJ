#include<iostream>
using namespace std;
int n,c,f[55][55][2]={0},d[55]={0},p[55]={0};
void init()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i]>>p[i];
		p[i]+=p[i-1];
	}
}
void dp()
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	f[i][j][0]=f[i][j][1]=0x7fffffff/2;
	f[c][c][0]=f[c][c][1]=0;
	for(int i=c;i>=1;i--)
	for(int j=c;j<=n;j++)
	{
		f[i][j][0]=min(f[i][j][0],f[i+1][j][0]+(d[i+1]-d[i])*(p[n]-(p[j]-p[i])));
		f[i][j][0]=min(f[i][j][0],f[i+1][j][1]+(d[j]-d[i])*(p[n]-(p[j]-p[i])));
		f[i][j][1]=min(f[i][j][1],f[i][j-1][1]+(d[j]-d[j-1])*(p[n]-(p[j-1]-p[i-1])));
		f[i][j][1]=min(f[i][j][1],f[i][j-1][0]+(d[j]-d[i])*(p[n]-(p[j-1]-p[i-1])));
	}
	cout<<min(f[1][n][1],f[1][n][0]);
}
int main()
{
	init();
	dp();
	return 0;
}
/*
5 3
2 10
3 20
5 20
6 30
8 10
*/