#include<iostream>
using namespace std;
int a[400]={0},f[50][50][50][50]={0},c[5]={0},n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,x;i<=m;i++){cin>>x;c[x]++;}
	for(int i=0;i<=c[1];i++)
	for(int j=0;j<=c[2];j++)
	for(int k=0;k<=c[3];k++)
	for(int l=0;l<=c[4];l++)
	{
		if(i>=1)f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l]);
		if(j>=1)f[i][j][k][l]=max(f[i][j][k][l],f[i][j-1][k][l]);
		if(k>=1)f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k-1][l]);
		if(l>=1)f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k][l-1]);
		f[i][j][k][l]+=a[i+j*2+k*3+l*4+1];
	}
	cout<<f[c[1]][c[2]][c[3]][c[4]]<<endl;
	return 0;
}
/*
9 5
6 10 14 2 8 8 18 5 17
1 3 1 2 1
*/