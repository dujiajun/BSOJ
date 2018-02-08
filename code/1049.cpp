#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int t[105],t1,v[105],f[1005][1005],m,i,j;
int main()
{
	cin>>t1>>m;
	for(i=1;i<=m;i++)cin>>t[i]>>v[i];
	for(i=1;i<=t1;i++)f[0][i]=0;
	for(i=1;i<=m;i++)f[i][0]=0;
	for(i=1;i<=m;i++)
	for(j=1;j<=t1;j++)
		if(j>=t[i])f[i][j]=max(f[i-1][j],f[i-1][j-t[i]]+v[i]);
		else f[i][j]=f[i-1][j];
	int ma=f[m][1];
	for(int i=t1;i>0;i--)if(ma<f[m][i])ma=f[m][i];
	cout<<ma;
	return 0;
}