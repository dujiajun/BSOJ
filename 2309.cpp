#include<iostream>
using namespace std;
int f[35][35]={0},n,m;
int main()
{
 	cin>>n>>m;f[1][0]=1;
	for(int j=1;j<=m;j++)
 	for(int i=1;i<=n;i++)
 	{
 		if(i==1){f[i][j]=f[2][j-1]+f[n][j-1];continue;}
 		if(i==n){f[i][j]=f[1][j-1]+f[n-1][j-1];continue;}
 		f[i][j]=f[i+1][j-1]+f[i-1][j-1];
 	}
 	cout<<f[1][m];
	return 0;
}
