#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[21],b[21],f[21][201];
void init()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a[i]>>b[i];
}
long long power(int x,int y)
{
	long long k=1;
	for(int i=1;i<=y;i++)k*=x;
	return k;	
}
long long gett(int x,int i){return a[i]*power(x,b[i]);}
void dp()
{
	for(int i=1;i<=m;i++)f[i][0]=0;
	for(int i=0;i<=m;i++)
	for(int j=1;j<=n;j++)f[i][j]=0xfffffff;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		for(int k=0;k<=j;k++)
		f[i][j]=min(f[i][j],f[i-1][k]+gett(j-k,i));
	}
}
int main()
{
    //freopen("mat.in","r",stdin);
    //freopen("mat.out","w",stdout);
	init();
	dp();
	cout<<f[m][n];
	return 0;
}
/*
10 3
2 1
1 2
2 1
*/
