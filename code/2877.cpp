#include<iostream>
#include<cstring>
using namespace std;
int n,map[300][300]={0},vst[300]={0},ans=0;
void dfs(int x,int dp)
{
	if(dp==n){ans++;return;}
	for(int i=1;i<=n;i++)
	if(map[x][i]&&!vst[i])
	{
		vst[i]=1;
		dfs(i,dp+1);
		vst[i]=0;
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)cin>>map[i][j];
	for(int i=1;i<=n;i++)
	{
		memset(vst,0,sizeof(vst));
		vst[i]=1;
		dfs(i,1);
	}
	cout<<ans<<endl;
	return 0;
}
/*
7
0 1 0 1 1 0 0
1 0 1 0 1 0 0
0 1 0 0 0 0 1
1 0 0 0 0 0 0
1 1 0 0 0 1 0
0 0 0 0 1 0 1
0 0 1 0 0 1 0
*/