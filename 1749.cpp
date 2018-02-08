#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int a[1001],f[1001][1001]={0},s[1001][1001]={0};
int main()
{
	int n,m,minn=0,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++)
	{
		s[i][i]=0;
		for(int j=i+1;j<=n;j++)s[i][j]=s[i][j-1]+abs(a[j]-a[(i+j)/2]);
	}
	for(int i=1;i<=n;i++)f[1][i]=s[1][i];
	for(int i=2;i<=m;i++)
	 for(int j=i;j<=n;j++)
	 {
	 	minn=0x7fffffff/2;
	 	for(k=i-1;k<=j-1;k++)
		 if(f[i-1][k]+s[k+1][j]<minn)minn=f[i-1][k]+s[k+1][j];
	 	f[i][j]=minn;
	 }
	 cout<<f[m][n];
	return 0;
}