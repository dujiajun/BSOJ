#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[55][55][55][55],n,m,map[55][55];
int main()
{
 	cin>>m>>n;
	for(int i=1;i<=m;i++)
  	for(int j=1;j<=n;j++)cin>>map[i][j];
	memset(f,0,sizeof(f));
 	for(int i=1;i<=m;i++)
  	for(int j=1;j<=n;j++)
   	for(int k=1;k<i+j;k++)
   	{
	   f[i][j][k][i+j-k]=max(max(f[i-1][j][k-1][i+j-k],f[i-1][j][k][i+j-k-1]),max(f[i][j-1][k-1][i+j-k],f[i][j-1][k][i+j-k-1]))+map[i][j]+map[k][i+j-k];
 	   if(i==k)f[i][j][k][i+j-k]-=map[i][j];
	}
	cout<<f[m][n][m][n];
	return 0; 
}
/*
3 3
0 3 9
2 8 5
5 7 0
*/