#include<iostream>
using namespace std;
int n,f[1005][1005]={0},map[1005][1005]={0},m;
int main()
{
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)
	{
		cin>>x>>y;
		map[x][y]=1;
	}
	f[1][1]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i-1>=1&&!map[i-1][j])f[i][j]=(f[i][j]+f[i-1][j])%100003;
		if(j-1>=1&&!map[i][j-1])f[i][j]=(f[i][j]+f[i][j-1])%100003;
		//f[i][j]=(f[i-1][j]+f[i][j-1])%100003;
	}
	cout<<f[n][n]<<endl;
	return 0;
}