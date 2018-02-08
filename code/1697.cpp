#include<iostream>
using namespace std;
int a[1005][1005]={0},f[1005][1005]={0};
int m,n,ans=-0xfffffff;

int min(int x,int y,int z){return min(min(x,y),z);}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)cin>>a[i][j];
	f[1][1]=a[1][1];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(a[i][j]==1)
		{
			f[i][j]=min(f[i-1][j-1],f[i-1][j],f[i][j-1])+1;
			ans=max(ans,f[i][j]);
		}
	}
	cout<<ans;
	return 0;
}