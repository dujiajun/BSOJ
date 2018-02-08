#include<iostream>
#include<cstring>
using namespace std;
int n,m,t,f[205][205]={0},w[205][205]={0},a[205]={0},v[205]={0},p[8005]={0};
void init()
{
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)cin>>a[i]>>v[i];
}
void dp_pre()
{
	for(int i=1;i<=n;i++)
	{
		memset(p,0,sizeof(p));
		for(int j=i;j<=n;j++)
		{
			for(int k=(n-i+1)*t;k>=a[j];k--)if(p[k-a[j]]+v[j]>p[k])p[k]=p[k-a[j]]+v[j];
			w[i][j]=p[t*(j-i+1)];
		}
	}
}
void dp_do()
{
	for(int i=1;i<=n;i++)f[1][i]=w[1][i];
	for(int i=2;i<=m;i++)
	for(int j=i;j<=n;j++)
	for(int k=i-1;k<=j-1;k++)
	if(f[i-1][k]+w[k+1][j]>f[i][j])f[i][j]=f[i-1][k]+w[k+1][j];
	cout<<f[m][n]<<endl;
}
int main()
{
	init();
	dp_pre();
	dp_do();
	return 0;
}
/*
2 1 2
2 1
3 2
*/