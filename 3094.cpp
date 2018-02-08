#include<iostream>
using namespace std;
long long n,a[505],sa[505],sb[505],b[505],f[505][505],g[505];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sa[i]=sa[i-1]+a[i];
		f[i][0]=-sa[i]*sa[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		sb[i]=sb[i-1]+b[i];
		f[0][i]=-sb[i]*sb[i];
	}
	long long p=f[n][0]+f[0][n],t=0;
	for(int i=1;i<=n+1;i++)
	for(int j=1;j<=n+1;j++)
	{
		t=a[i]*b[j];
		f[i][j]=p;
		if(j==1)f[i][j]=max(f[i][j],f[i-1][0]+t);
		else
		{
			for(int k=0;k<=i-1;k++)f[i][j]=max(f[i][j],f[k][j-1]-(sa[i-1]-sa[k])*(sa[i-1]-sa[k])+t);
		}
		if(i==1)f[i][j]=max(f[i][j],f[0][j-1]+t);
		else
		{
			for(int k=0;k<=j-1;k++)f[i][j]=max(f[i][j],f[i-1][k]-(sb[j-1]-sb[k])*(sb[j-1]-sb[k])+t);
		}	
	}
	cout<<f[n+1][n+1]<<endl;
	return 0;
}
/*
3 
1 
1 
5 
5 
1 
1
*/