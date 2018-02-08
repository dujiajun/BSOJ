#include<iostream>
#include<cmath>
using namespace std;

int main()
{
 	int n;
 	cin>>n;
 	int a[n+1][n+1];
 	for(int i=1;i<=n;i++)
 	for(int j=1;j<=i;j++)cin>>a[i][j];
 	int f[n+1][n+1];
 	for(int i=1;i<=n;i++)f[n][i]=a[n][i];
 	for(int i=n-1;i>=1;i--)
 	for(int j=1;j<=i;j++)
 	f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
 	cout<<f[1][1];
	return 0;
}
