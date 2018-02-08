#include<iostream>
#include<cstdio>
using namespace std;
int s[3005][3005]={0},f[3005][3005]={0};
int m,n,ans=0,w,h;

int min(int x,int y,int z){return min(min(x,y),z);}
int main()
{
	cin>>m>>n>>w>>h;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)scanf("%d",&s[i][j]);
	f[1][1]=s[1][1];
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
			f[i][j]=s[i][j]+f[i][j-1]+f[i-1][j]-f[i-1][j-1];
	for(int i=w;i<=m;i++)
	for(int j=h;j<=n;j++)
			ans=max(f[i][j]-f[i][j-h]-f[i-w][j]+f[i-w][j-h],ans);
	cout<<ans;
	return 0;
}